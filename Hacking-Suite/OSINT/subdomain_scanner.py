import requests
import json
import os

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
    return subdomains

def main():
    domain = input("Enter a domain: ")
    subdomains = subdomain_scanner(domain)
    
    wildcard_subdomains = sorted([sub for sub in subdomains if sub.startswith('*.')])
    non_wildcard_subdomains = sorted([sub for sub in subdomains if not sub.startswith('*.')])
    
    all_subdomains = {
        "wildcard_subdomains": wildcard_subdomains,
        "non_wildcard_subdomains": non_wildcard_subdomains
    }
    
    # Print to terminal
    for subdomain in wildcard_subdomains + non_wildcard_subdomains:
        print(f"Discovered: {subdomain}")
    
    # Write to JSON file
    sanitized_domain = domain.replace('.', '_')
    output_path = os.path.join(r'E:\Extra-Projects\Hacking-Suite\OSINT\Output', f'{sanitized_domain}_subdomains.json')
    os.makedirs(os.path.dirname(output_path), exist_ok=True)
    
    with open(output_path, 'w') as json_file:
        json.dump(all_subdomains, json_file, indent=4)
        
if __name__ == "__main__":
    main()