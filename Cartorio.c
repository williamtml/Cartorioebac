#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de epaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo função Write (Escrever)
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo função Atualizar
	fprintf(file,","); //coloca a vírgula no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Caixa de pergunta
	scanf("%s", nome); //Salva o que foi digitado na variável nome
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file,nome); //salva a variável nome no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file,","); //coloca a vírgula no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Caixa de pergunta
	scanf("%s", sobrenome); //Salva o que foi digitado na variável sobrenome
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file,sobrenome); //salva a variável sobrenome no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file,","); //coloca a vírgula no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Caixa de pergunta
	scanf("%s", cargo); //Salva o que foi digitado na variável cargo
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file,cargo); //salva a variável cargo no arquivo
	fclose(file); //fecha o arquivo
	
	system("pause"); //Pausa para o cliente ver a mensagem
		
}

int consulta()
{
	setlocale(LC_ALL, "PORTUGUESE"); //definindo a linguagem

	//início da criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//fim da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: "); //Caixa de pergunta
	scanf("%s", cpf); //Salvando o que foi digitado na variável CPF
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //Abre o arquivo no modo de letura R de READ - LER
	
	if(file==NULL) //Se não validar, seguir com a resposta abaixo.
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Enquanto tiver conteudo dentro do arquivo, ele vai armazenando e depois que terminar trás as informações
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo); //trás as informações que estão dentro de conteudo
		printf("\n\n"); //pula linha
	}
	
	system("pause"); //pausa para visualização do cliente
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: "); //Caixa de pergunta
	scanf("%s", cpf); //Salvando o que foi digitado na variável CPF
	
	remove(cpf); //deleta o que tem dentro de CPF
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //Abre o arquivo no modo de letura R de READ - LER
	
	if(file == NULL); //se arquivo for nulo (não validar)
	{
		printf("O usuário não se encontra no ssitema!.\n");
		system("pause");
	}
}


int main ()
{
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //responsável por limpar os dados
	
		setlocale(LC_ALL, "PORTUGUESE"); //definindo a linguagem
	
		printf("###Cartório da EBAC###\n\n"); //início do menu
		printf("Por gentileza, escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //falando para o sistema limpar a tela
		
		switch(opcao)  //switch case  - Simplificando ao invés de utilizar o if nesse caso (início da seleção de menu)
		{
			case 1: 
			registro(); //chamada de funções
			break;
			
			case 2: 
			consulta(); //chamada de funções
			break;
			
			case 3: 
			deletar(); //chamada de funções
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
		} //fim da seleção
	
	}
}
