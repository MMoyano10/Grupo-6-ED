#include <string>
using namespace std;

class Ingreso{
	public:
		int convertirDatoEntero(std::string cad);
		float convertirDatoDecimal(std::string cad);
		char convertirDatoCaracter(std::string cad);
		bool esUnNumero(std::string cad);
		bool esUnFloat(std::string cad);
};

