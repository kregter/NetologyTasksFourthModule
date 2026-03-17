#include <iostream>
#include <string>
#include <map>



int main()
{
	setlocale(LC_ALL, "rus");
	
	std::string input;
	std::cout << "[IN]: ";
	std::getline(std::cin, input);

	std::map<char, int> letters{};

	for (const auto& ch : input) {
		auto it = letters.find(ch);
		if (it != letters.end()) {
			it->second++;
		}
		else {
			letters[ch] = 1;
		}
	}

	std::multimap<int, char> letters_sorted{};

	for (const auto& let : letters) {
		letters_sorted.insert({ let.second, let.first });
	}
	
	std::cout << "[OUT]: " << std::endl;

	for (auto let = letters_sorted.rbegin(); let != letters_sorted.rend(); ++let) {
		std::cout << let->second << ": " << let->first << std::endl;
	}


	return 0;

}