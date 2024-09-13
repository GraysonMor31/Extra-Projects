import dns.resolver

def dns_enum(domain):
    records = ["A", "AAAA", "MX", "NS", "TXT", "SOA"]
    for record in records:
        try:
            answers = dns.resolver.resolve(domain, record)
        except dns.resolver.NoAnswer:
            continue
        print(f"DNS records for {domain} ({record})")
        for answer in answers:
            print(answer)
        
def main():
    domain = input("Enter a domain: ")
    print(dns_enum(domain))
    
if __name__ == "__main__":
    main()
            