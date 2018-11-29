#include <iostream>
#include <string>
#include <map>
#include <locale>
#include "cad_residuos.h"


   Cad_residuos::Cad_residuos()
   {
      std::map<std::string ,std::string >lst;
      lst.insert(std::pair<std::string,std::string>("a�o de constru��o","Manter em local coberto, protegido da umidade e as arestas devem ser chanfradas" ));
      lst.insert(std::pair<std::string,std::string>("arame","Manter em local seco, enrolado em bobina e envolvido por material protetor" ));
      lst.insert(std::pair<std::string,std::string>("pl�sticos de consumo dom�stico","Manter protegido de materiais combust�veis e longe de fontes de calor"));
      lst.insert(std::pair<std::string,std::string>("vidros de consumo dom�stico","Deve estar dentro de inv�lucro flex�vel e envolto por papel, com informa��o de\nconte�do externamente vis�vel." ));
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
           std::cout<<"Res�duo: ["<<it.first<<"]\nArmazenamento:\t"<<it.second<<"\n\n"<<std::endl;
       }
   }
