import whois
import requests
import dns.resolver
import json
import os
import datetime

def is_registered(domain):
    try:
        name = whois.whois(domain)
    except Exception:
        return False
    else:
        return bool(name.domain)
    
def extract_domain_info(domain):
    if is_registered(domain):
        name_info = whois.whois(domain)
        name = name_info.domain_name
        registrar = name_info.registrar
        creation_date = name_info.creation_date
        expiration_date = name_info.expiration_date
        name_servers = name_info.name_servers
        
        # Handle list cases for creation_date and expiration_date
        if isinstance(creation_date, list):
            creation_date = creation_date[0]
        if isinstance(expiration_date, list):
            expiration_date = expiration_date[0]
        
        return {
            "domain_name": name,
            "registrar": registrar,
            "creation_date": creation_date.strftime('%Y-%m-%d %H:%M:%S') if creation_date else None,
            "expiration_date": expiration_date.strftime('%Y-%m-%d %H:%M:%S') if expiration_date else None,
            "name_servers": name_servers
        }
    else:
        print("Domain is not registered")
        return None
    
def dns_enum(domain):
    records = ["A", "AAAA", "MX", "NS", "TXT", "SOA"]
    dns_records = {}
    for record in records:
        try:
            answers = dns.resolver.resolve(domain, record)
            dns_records[record] = [str(answer) for answer in answers]
        except dns.resolver.NoAnswer:
            dns_records[record] = []
        except dns.resolver.NXDOMAIN:
            dns_records[record] = []
    return dns_records
            
def subdomain_scanner(domain):
    url = f"https://crt.sh/?q=%25.{domain}&output=json"
    response = requests.get(url)
    subdomains = set()
    if response.ok:
        data = response.json()
        for entry in data:
            # Split entries that contain multiple subdomains
            for subdomain in entry["name_value"].split('\n'):
                # Filter out any invalid entries
                if subdomain and subdomain.endswith(domain):
                    subdomains.add(subdomain)
    return sorted(subdomains)

def main():
    domain = input("Enter a domain: ")
    
    # Extract domain info
    domain_info = extract_domain_info(domain)
    
    # DNS enumeration
    dns_records = dns_enum(domain)
    
    # Subdomain scanning
    subdomains = subdomain_scanner(domain)
    
    # Print to terminal
    if domain_info:
        print("\nDomain Information:")
        for key, value in domain_info.items():
            print(f"{key.replace('_', ' ').title()}: {value}")
    
    print("\nDNS Records:")
    for record_type, records in dns_records.items():
        print(f"{record_type} Records:")
        for record in records:
            print(f"  {record}")
    
    print("\nSubdomains:")
    for subdomain in subdomains:
        print(f"Discovered: {subdomain}")
    
    # Write to JSON file
    sanitized_domain = domain.replace('.', '_')
    output_path = os.path.join(r'E:\Extra-Projects\Hacking-Suite\OSINT\Output', f'{sanitized_domain}_info.json')
    os.makedirs(os.path.dirname(output_path), exist_ok=True)
    
    output_data = {
        "domain_info": domain_info,
        "dns_records": dns_records,
        "subdomains": subdomains
    }
    
    with open(output_path, 'w') as json_file:
        json.dump(output_data, json_file, indent=4)
        
if __name__ == "__main__":
    main()