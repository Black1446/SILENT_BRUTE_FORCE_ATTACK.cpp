#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

// Function-ka brute force oo aan isticmaalin wordlist
void brute_force_without_wordlist(std::string target_password, std::string current, int max_length)
{
    if (current.length() == max_length) return; // Haddii dhererka uu gaaro xadka, jooji

    std::string chars = 
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789(;?,:'-)][>*&<^_%/₹=#@!+×÷=¿¡》《¤▪︎☆°•○●□■♤♡◇♧$¥£€}{|\\~`.";

    for (char c : chars) {
        std::string attempt = current + c; // Abuur isku darka cusub
        std::cout << "Isku day: " << attempt << std::endl;

        if (attempt == target_password) {
            std::cout << "Password-ka saxda ah waa: " << attempt << std::endl;
            return; // Haddii password-ka la helo, jooji barnaamijka
        }

        brute_force_without_wordlist(target_password, attempt, max_length); // Recursive call
    }
}

// Function-ka brute force iyadoo la isticmaalayo wordlist
void brute_force_with_wordlist(std::string target_password, std::string wordlist_file)
{
    std::ifstream wordlist(wordlist_file);

    if (!wordlist) {
        std::cout << "Faylka wordlist-ka lama helin!" << std::endl;
        return;
    }

    std::string word;
    while (std::getline(wordlist, word)) { // Si taxadar leh uga akhri ereyada wordlist-ka
        std::cout << "Isku day: " << word << std::endl;

        if (word == target_password) {
            std::cout << "Password-ka saxda ah waa: " << word << std::endl;
            return; // Haddii password-ka la helo, jooji barnaamijka
        }
    }

    std::cout << "Password lama helin!" << std::endl;
}

// Main function
int main()
{
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string RESET = "\033[0m";

    std::cout << GREEN;
    std::cout << R"(
██████╗ ██████╗ ██╗   ██╗████████╗███████╗    ███████╗ ██████╗  ██████╗███████╗    █████╗ ████████╗ ██████╗ ██████╗ 
██╔══██╗██╔══██╗██║   ██║╚══██╔══╝██╔════╝    ██╔════╝██╔═══██╗██╔════╝██╔════╝   ██╔══██╗╚══██╔══╝██╔════╝██╔══██╗
██║  ██║██████╔╝██║   ██║   ██║   █████╗      █████╗  ██║   ██║██║     █████╗     ███████║   ██║   ██║     ██████╔╝
██║  ██║██╔═══╝ ██║   ██║   ██║   ██╔══╝      ██╔══╝  ██║   ██║██║     ██╔══╝     ██╔══██║   ██║   ██║     ██╔═══╝ 
██████╔╝██║     ╚██████╔╝   ██║   ███████╗    ███████╗╚██████╔╝╚██████╗███████╗    ██║  ██║   ██║   ╚██████╗██║     
╚═════╝ ╚═╝      ╚═════╝    ╚═╝   ╚══════╝    ╚══════╝ ╚═════╝  ╚═════╝╚══════╝    ╚═╝  ╚═╝   ╚═╝    ╚═════╝╚═╝     
    )" << std::endl;
    std::cout << RESET;
    std::cout << "\033[1;31m⚠️ WARNING: Fadlan ha u isticmaal inaad dhibaateyso dadka, kaliya waxbarasho! ⚠️\033[0m\n";

    // Qeexida variables
    std::string target_password, username, gmail, facebook, tiktok, instagram, twitter;
    int option;

    std::cout << "\033[1;32m1 : Facebook" << std::endl;
    std::cout << "2 : Tiktok" << std::endl;
    std::cout << "3 : Gmail" << std::endl;
    std::cout << "Fadlan gali numberka bogga aad dooratay: \033[0m";
    std::cin >> option;

    // Doorashada platform-ka
    if (option == 1)
    {
        std::cout << "Fadlan gali target username-ka: ";
        std::cin >> username;
        std::cout << "Facebook username-ka waa: " << username << std::endl;
        target_password = username; // Username waa password-ka loo doortay
    }
    else if (option == 2)
    {
        std::cout << "Fadlan gali Tiktok username-ka: ";
        std::cin >> username;
        std::cout << "Tiktok username-ka waa: " << username << std::endl;
        target_password = username; // Username waa password-ka loo doortay
    }
    else if (option == 3)
    {
        std::cout << "Fadlan gali Gmail-ka: ";
        std::cin >> gmail;
        std::cout << "Gmail target waa: " << gmail << std::endl;
        target_password = gmail; // Gmail-ka waa password-ka loo doortay
    }
    else
    {
        std::cout << "Xulasho khaldan! Isku day mar kale." << std::endl;
        return 0;
    }

    // Xulashada habka brute force
    int method_option;
    std::cout << "\nFadlan dooro habka baaritaanka:\n";
    std::cout << "1 : Ka shaqee Brute Force adigoon isticmaalin wordlist\n";
    std::cout << "2 : Isticmaal wordlist si aad u baaro password-ka\n";
    std::cout << "Fadlan gali option-ka: ";
    std::cin >> method_option;

    if (method_option == 1) {
        // Ka shaqee brute force adigoon isticmaalin wordlist
        int max_length = 8; // Dhererka ugu badan ee password-ka
        brute_force_without_wordlist(target_password, "", max_length);
    }
    else if (method_option == 2) {
        // Isticmaal wordlist si aad u baaro password-ka
        std::string wordlist_file ;
        std::cout<<"fadlan kusoo darso wordlist file kaaga :  "<<std::endl; 
        std::cin>>wordlist_file;
        brute_force_with_wordlist(target_password, wordlist_file);
    }
    else {
        std::cout << "Xulasho khaldan! Barnaamijku wuxuu istaagi doonaa." << std::endl;
    }

    return 0;
}
