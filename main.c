//
//  main.c
//  cartorio_ebac_nelson
//
//  Created by Nelson Nogueira on 03/06/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>


int registro(void)//resp por cadastrar os usuários

{
    char arquivo [40];//inicia criação de variáveis
    char cpf [40];
    char nome [40];
    char sobrenome [40];
    char cargo [40];//finaliza criação de variáveis
    
    printf("Digite o CPF a ser cadastrado: ");//coleta informação usuário
    scanf("%s" , cpf);//refere-se a strings (%s)
    
    strcpy(arquivo, cpf);//copiar os valores da string
    
    FILE *file;//crir arquivo de banco de dados
    file = fopen(arquivo, "w");//abre o arquivo e escreve
    fprintf(file, cpf);//
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo, "a");//abre o arquivo
    fprintf(file, ",");//insere vírgula
    fclose(file);//fecha arquivo
    
    printf("Digite o NOME a ser cadastrado: ");//solicita nome
    scanf("%s" , nome);//armaneza
    file = fopen(arquivo, "a");//abre o arquivo
    fprintf(file, nome);//
    fclose(file);//fecha o arquivo
    
    printf("Digite o SOBRENOME a ser cadastrado: ");
    scanf("%s" , sobrenome);
    file = fopen(arquivo, "a");//abre o arquivo
    fprintf(file, sobrenome);
    fclose(file);//fecha o arquivo
    
    printf("Digite o CARGO a ser cadastrado: ");
    scanf("%s" , cargo);
    file = fopen(arquivo, "a");//abre o arquivo
    fprintf(file, cargo);
    fclose(file);//fecha o arquivo

    return 0; //criado por consulta no GPT, pois apresentava erro
}

int consulta(void)
{
    setlocale(LC_ALL, "Portuguese");
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado ");
    scanf("%s" ,cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if (file == NULL)
    {
    printf("CPF não localizado. Tente novamente/n");
        
    }
    while (fgets(conteudo, 200, file) != NULL)
    {
    printf("\n Essas informações são de um usuário válido");
    printf("%s", conteudo);
    printf("\n\n");
    }
    
    system("pause");
        
    return 0; //criado por consulta no GPT, pois apresentava erro
    }
    
int deleta(void)
{
    char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s" , cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if (file == NULL)
    {
    printf("O usuário é inválido\n");
    system("pause");
    }

    return 0;
}

int main(void) // void inserido conforme correção do xcode
{
        //setenv("TERM", "xterm-256color", 1); //inserido conforme informações stackoverflow
    
        int opcao=0;
        int laco=1;
        char senhadigitada[11]="a";
        printf("### CARTÓRIO EBAC - FILIAL ALUNO NELSON #### \n");
        printf("Login de Adm!\n\nDigite a sua senha: ");
        scanf("%s",senhadigitada);
    
        if (strcmp(senhadigitada, "admin") == 0)//strcmp inserido após erro. consulta no stackoverflow
        {
            system("clear");
        
        for(laco=1;(laco=1);) //inserido mais um conjunto de parentesis pelo próprio Xcode
        {
        system("clear"); //alterado para clear por determinação da IDE xcode (MacOs)
        
        setlocale(LC_ALL, "Portuguese");
        
        printf("### CARTÓRIO EBAC - FILIAL ALUNO NELSON #### \n");
        printf("\tEscolha a opção desejada no menu abaixo: \n\n");
        printf("\t1 - Cadastrar Usuários \n\n");
        printf("\t2 - Consultar Registros \n\n");
        printf("\t3 - Deletar Registros \n\n");
        printf("\t4 - Sair do sistema \n\n");

        printf("\t Digite a opção:  ");
        
        scanf("%d", &opcao);//armaneza a opção escolhida
        
        system("clear");//alterado para clear por determinação da IDE xcode
        
        switch (opcao)
        {
        case 1: //inicio seleção
        registro();
        break;
                
        case 2:
        consulta();
        break;
                
        case 3:
        deleta();
        break;
        
        case 4:
        printf("Obrigado por usar nosso sistema \n");
        return 0;
        break;
    
        default:
        printf("Esta opção não existe, escolha outra alternativa");
        getchar(); //substituído por getchar stackoverflow, devido ser MacOs
        break;
        } //fim da seleção
    
    }
}
    else//compara se a senha está correta
    {
    printf("Senha incorreta\n");
    }
    return 0;//instrução inserida após consulta gpt...sem ela dá erro (MacOs)
    }


