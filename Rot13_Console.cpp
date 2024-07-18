#include <iostream>
#include <string>
#include <regex>

std::string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
std::string letters_rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm0123456789";

void Encrypt(std::string inp)
{
    if (inp == "")
        std::invalid_argument("EXC: Argument NULL or empty!");

    std::regex rgx("_");
    std::vector<std::string> input;
    std::sregex_token_iterator iter(inp.begin(),
        inp.end(),
        rgx,
        -1);
    std::sregex_token_iterator end;

    for (; iter != end; ++iter)
        input.emplace_back(*iter);

    std::string data = input[1];
    int s = data.size();
    std::string res = "";
    for (int i = 0; i < s; ++i)
    {
        unsigned int pos = letters.find(data[i]);
        res.append(1u, letters_rot13[pos]);
    }

    std::cout << "Input Encrypted: " << res << "\n";

}

void Decrypt(std::string inp)
{
    if (inp == "")
        std::invalid_argument("EXC: Input NULL or empty!");
    
    
    std::regex rgx("_");
    std::vector<std::string> input;
    std::sregex_token_iterator iter(inp.begin(),
        inp.end(),
        rgx,
        -1);
    std::sregex_token_iterator end;
    
    for (; iter != end; ++iter)
        input.emplace_back(*iter);

    std::string data = input[1];
    int s = data.size();
    std::string res = "";
    for (int i = 0; i < s; ++i)
    {
        unsigned int pos = letters_rot13.find(data[i]);
        res.append(1u, letters[pos]);
    }

    std::cout << "Input Decrypted: " << res << "\n";

}

int main()
{
    std::cout << "Rot13\n";
    while (true)
    {
        std::string inp;
        std::cin >> inp;

        if (inp.find("enc_") != std::string::npos)
            Encrypt(inp);
        if (inp.find("dec_") != std::string::npos)
            Decrypt(inp);
        if (inp == "quit")
            break;
    }
}