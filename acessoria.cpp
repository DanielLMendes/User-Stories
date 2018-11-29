#include <string>
#include <iostream>
#include "acessoria.h"

int cta_espacos(std::string str)
{
    int n = 0;
    for(int i=0;i<str.length();i++)
        if(str[i] == ' ')
            n++;
    return n;
}
//------------------------------------------------------------------------------------------
int cta_non_zeros(std::string str)
{
    int n = 0;
    for(int i=0;i<=str.size();i++)
        if(str[i]>48&&str[i]<58)
            n++;
    return n;
}
//------------------------------------------------------------------------------------------
bool e_alpha(std::string str)
{
    int i,test;
    for(i=0;i<=str.length();i++)
    {
        test = (int)str[i];
        if((test>0&&test<32)||(test>32&&test<65)||(test>90&&test<97)||test>122)
        {
            return false;
        }
    }
    return true;
}
//------------------------------------------------------------------------------------------
bool e_num(std::string str)
{
    int i,test;
    for(i=0;i<=str.length();i++)
    {
        test = (int)str[i];
        if(test>0&&(test<48||test>57))
        {
            return false;
        }
    }
    return true;
}
//------------------------------------------------------------------------------------------
char valida_tp_pessoa()
{
    char resp;
    do
    {
        fflush(stdin);
        std::cout<<">>>>>>>>>>> Digite \"1\" para Pessoa Física ou \"2\" para Pessoa Jurídica\n"<<std::endl;
        std::cin>>resp;
    }while(resp!='1' && resp!='2');
}
//------------------------------------------------------------------------------------------
std::string valida_nome(bool tp)
{
    bool erro = false;
    std::string temp = " ";
    do
    {
        erro = false;
        std::cout<<">>>>>>>>>>> Digite o nome:\n"<<std::endl;
        fflush(stdin);
        std::getline(std::cin, temp,'\n');

        if(e_alpha(temp)==false)
        {
            std::cout<<"\nO nome não deve conter número(s) nem caracteres especiais!\n";
            erro = true;
        }
        else
        {
                int it = cta_espacos(temp);
                if(it==0)
                {
                    if(tp)
                    {
                        std::cout<<"\nDeve haver ao menos a qualificação da pessoa jurídica(LTDA,SA,etc) \n";
                        erro = true;

                    }
                    else
                    {
                        std::cout<<"\nDeve haver ao menos um sobrenome para a pessoa!\n";
                        erro = true;
                    }

                };
        }
    }while(erro == true);
    return temp;
}
//------------------------------------------------------------------------------------------
std::string valida_cad_receita(bool tp)
{
    std::string tipo = " ";
    bool erro = false;
    std::string temp;
    int it = 0;
    bool test = false;
    tipo = (tp==true)?"CNPJ":"CPF";
    do
    {
        std::cout<<">>>>>>>>>>> Digite o número do "<<tipo<<" de forma direta:\n"<<std::endl;
        fflush(stdin);
        std::getline(std::cin, temp,'\n');
        erro = false;
        it = cta_non_zeros(temp);
        test = e_num(temp);
        if(test==false)
        {
            erro = true;
            std::cout<<"\nA entrada deve ser numérica! \n";
        }
        else
        {
            int soma=0;
            for(int i=0;i<=temp.size();i++)
            {
                if(temp[i]>47&&temp[i]<58)
                    soma++;
            }
            if(tp==false)
            {
                if(it<4||soma>11)
                {
                    erro = true;
                    std::cout<<"\nO CPF deve conter pelo menos um algarismo não nulo,além do código para Estado e DV,tendo no máximo 11 algarismos ao todo.\n";
                }
            }
        }
    }while(erro == true);
    return temp;
}



