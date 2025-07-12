import std;

int main()
{
	std::string xmlEsq{ "<Objetivo " };

	std::string curso{ "curso = \"Python\" " };
	std::string modulo{ "modulo = \"" };
	std::string aula{ " aula = \"" };

	std::string objetivos{ "> obj ax mx" };

	std::string xmlDir{ " </Objetivo>" };

	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			std::cout << xmlEsq << curso << modulo << i << '\"' << aula << j << '\"' << objetivos << xmlDir << '\n';
		}
		std::cout << '\n';
	}
}