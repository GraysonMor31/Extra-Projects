int main(){
    // XOR INTS
    int a = 5;
    int b = 6;
    int c = a ^ b;
    std::cout << c << std::endl;
    
    // XOR BINARY
    int d = 0b101;
    int e = 0b110;
    int f = d ^ e;
    std::cout << f << std::endl;

    // XOR HEX
    int g = 0x5;
    int h = 0x6;
    int i = g ^ h;
    std::cout << i << std::endl;

    // XOR STRINGS
    std::string j = "Hello";
    std::string k = "World";
    std::string l = j ^ k;
    std::cout << l << std::endl;

    // XOR CHAR ARRAYS
    char m[] = "Hello";
    char n[] = "World";
    char o[] = m ^ n;
    std::cout << o << std::endl;

    // XOR CHAR POINTERS
    char *p = "Hello";
    char *q = "World";
    char *r = p ^ q;
    std::cout << r << std::endl;

    // XOR CHAR VECTORS
    std::vector<char> s = {'H', 'e', 'l', 'l', 'o'};
    std::vector<char> t = {'W', 'o', 'r', 'l', 'd'};
    std::vector<char> u = s ^ t;
    std::cout << u << std::endl;

    return 0;
}