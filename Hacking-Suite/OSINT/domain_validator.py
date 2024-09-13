import whois

def is_registered(domain):
    try:
        name = whois.whois(domain)
    except Exception:
        return False
    else:
        return bool(name.domain)
    
def main():
    domain = input("Enter a domain: ")
    if is_registered(domain):
        print("Domain is registered")
    else:
        print("Domain is not registered")

if __name__ == "__main__":
    main()