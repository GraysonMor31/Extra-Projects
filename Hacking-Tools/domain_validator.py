import whois

def is_registered(domain_name):
    """
    A function that returns a boolean indicating 
    whether a `domain_name` is registered
    """
    try:
        w = whois.whois(domain_name)
        print(w)
    except Exception:
        return False
    else:
        return bool(w.domain_name)
    
if __name__ == "__main__":
    print(is_registered("google.com"))
    print(is_registered("mySQL.com"))
    print(is_registered("notadomain.com"))