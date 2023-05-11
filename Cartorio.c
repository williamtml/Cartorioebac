#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de epa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo fun��o Write (Escrever)
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo fun��o Atualizar
	fprintf(file,","); //coloca a v�rgula no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Caixa de pergunta
	scanf("%s", nome); //Salva o que foi digitado na vari�vel nome
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file,nome); //salva a vari�vel nome no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file,","); //coloca a v�rgula no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Caixa de pergunta
	scanf("%s", sobrenome); //Salva o que foi digitado na vari�vel sobrenome
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file,sobrenome); //salva a vari�vel sobrenome no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file,","); //coloca a v�rgula no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Caixa de pergunta
	scanf("%s", cargo); //Salva o que foi digitado na vari�vel cargo
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file,cargo); //salva a vari�vel cargo no arquivo
	fclose(file); //fecha o arquivo
	
	system("pause"); //Pausa para o cliente ver a mensagem
		
}

int consulta()
{
	setlocale(LC_ALL, "PORTUGUESE"); //definindo a linguagem

	//in�cio da cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//fim da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); //Caixa de pergunta
	scanf("%s", cpf); //Salvando o que foi digitado na vari�vel CPF
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //Abre o arquivo no modo de letura R de READ - LER
	
	if(file==NULL) //Se n�o validar, seguir com a resposta abaixo.
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Enquanto tiver conteudo dentro do arquivo, ele vai armazenando e depois que terminar tr�s as informa��es
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo); //tr�s as informa��es que est�o dentro de conteudo
		printf("\n\n"); //pula linha
	}
	
	system("pause"); //pausa para visualiza��o do cliente
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //Caixa de pergunta
	scanf("%s", cpf); //Salvando o que foi digitado na vari�vel CPF
	
	remove(cpf); //deleta o que tem dentro de CPF
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //Abre o arquivo no modo de letura R de READ - LER
	
	if(file == NULL); //se arquivo for nulo (n�o validar)
	{
		printf("O usu�rio n�o se encontra no ssitema!.\n");
		system("pause");
	}
}


int main ()
{
	int opcao=0; //definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //respons�vel por limpar os dados
	
		setlocale(LC_ALL, "PORTUGUESE"); //definindo a linguagem
	
		printf("###Cart�rio da EBAC###\n\n"); //in�cio do menu
		printf("Por gentileza, escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //falando para o sistema limpar a tela
		
		switch(opcao)  //switch case  - Simplificando ao inv�s de utilizar o if nesse caso (in�cio da sele��o de menu)
		{
			case 1: 
			registro(); //chamada de fun��es
			break;
			
			case 2: 
			consulta(); //chamada de fun��es
			break;
			
			case 3: 
			deletar(); //chamada de fun��es
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		} //fim da sele��o
	
	}
}
