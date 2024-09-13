import whois
from domain_validator import is_registered
from datetime import datetime

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
        
        return name, registrar, creation_date, expiration_date, name_servers
    else:
        print("Domain is not registered")
        return None, None, None, None, None
        
def main():
    domain = input("Enter a domain: ")
    name, registrar, creation_date, expiration_date, name_servers = extract_domain_info(domain)
    
    if name:
        print(f"Domain name: {name}")
        print(f"Registrar: {registrar}")
        print(f"Name servers: {name_servers}")
        print(f"Creation date: {creation_date.strftime('%Y-%m-%d %H:%M:%S')}")
        print(f"Expiration date: {expiration_date.strftime('%Y-%m-%d %H:%M:%S')}")
    
if __name__ == "__main__":
    main()