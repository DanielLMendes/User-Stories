#ifndef CAD_USR_H_INCLUDED
#define CAD_USR_H_INCLUDED
#include <set>
#include <map>
#include <string>

class Cad_usr
{
    private:
        bool pj;    //Indica se � pessoa jur�dica.
        std::string cad_receita;    //C.P.F. ou C.N.P.J. da pessoa.
        std::string nome;
        std::string* endereco;  //Cidade,bairro,logradouro e n�mero, em ordem.
        std::map<std::string,std::string>locais_coleta;/*Um "map" de endere�os onde o doador/receptor
        aceita doar/receber o material*/
        std::set<std::string>tipos_residuo;/*Um "set" de res�duos de interesse
        para o doador/receptor.*/

    public:
        Cad_usr();
        ~Cad_usr();
        bool pega_tp_pessoa();
        std::string pega_nome();
        std::string pega_cpf_cnpj();
        std::string* pega_endereco();
        bool acha_local(std::string*); //Verifica se o local � de interesse da pessoa
        bool acha_res(std::string); //Verifica se o res�duo � de interesse para a pessoa
        void adiciona_res();
        void adiciona_local();
        void exclui_res();
        void exclui_local();
};
#endif // CAD_USR_H_INCLUDED
