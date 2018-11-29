#ifndef CAD_RESIDUOS_H_INCLUDED
#define CAD_RESIDUOS_H_INCLUDED
#include <map>

class Cad_residuos
{

    private:
        std::map<std::string,std::string>lista;
    public:
        Cad_residuos();
        ~Cad_residuos();
        bool consulta_residuo(std::string);
        void imprime();
};


#endif // CAD_RESIDUOS_H_INCLUDED
