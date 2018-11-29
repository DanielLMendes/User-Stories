#include <iostream>
#include <string>
#include <map>
#include <locale>
#include "cad_residuos.h"


   Cad_residuos::Cad_residuos()
   {
      std::map<std::string ,std::string >lst;
      lst.insert(std::pair<std::string,std::string>("aço de construção","Manter em local coberto, protegido da umidade e as arestas devem ser chanfradas" ));
      lst.insert(std::pair<std::string,std::string>("arame","Manter em local seco, enrolado em bobina e envolvido por material protetor" ));
      lst.insert(std::pair<std::string,std::string>("plásticos de consumo doméstico","Manter protegido de materiais combustíveis e longe de fontes de calor"));
      lst.insert(std::pair<std::string,std::string>("vidros de consumo doméstico","Deve estar dentro de invólucro flexível e envolto por papel, com informação de\nconteúdo externamente visível." ));
      lista = lst;
   };

   Cad_residuos::~Cad_residuos(){};

   bool Cad_residuos::consulta_residuo(std::string rsd )
   {
       std::map<std::string,std::string>::iterator it;
       for(int i = 0;i < rsd.length();i++)
            rsd[i] = tolower(rsd[i]);
       it = this->lista.find(rsd);
       if(it==this->lista.end())
            return false;
       else
            return true;
   }

   void Cad_residuos::imprime()
   {

       for(auto it:this->lista)
       {
           std::cout<<"Resíduo: ["<<it.first<<"]\nArmazenamento:\t"<<it.second<<"\n\n"<<std::endl;
       }
   }
