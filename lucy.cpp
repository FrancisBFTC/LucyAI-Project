#include "lucy.h" 

int main(int argc, char** argv)
{	
	if(argc == 1){
		printf("Lucy API version 1.0.0\n");
		printf("Author: By Wenderson Francisco\n");
		printf("usage: lucy [--train] [--pred] [--info]");
		return 0;
	}
	
	Lucy lucy;
	lucy.create_network(1);							// Crie uma rede neural
	
	char* dataset[] = { 
		"quadrados", 			// Pasta de dataset 1
		"triangulos" 			// Pasta de dataset 2
	};
	
	char* labels[] = {
		"QUADRADO",				// Label do classe 1
		"TRIANGULO"				// Label do classe 2
	};
	
	int epochs = 0;
	double learning = 0.0;
	bool isTransfer = false;
	
	for(int i = 1; i < argc; i++){
		if(strcmp(argv[i], "--train") == 0){
			if(argv[++i] != NULL){
				char* name = argv[i];
				for(; i < argc; i++){
					if(strcmp(argv[i], "-e") == 0)
						epochs = atoi(argv[++i]);
					if(strcmp(argv[i], "-l") == 0)
						learning = atof(argv[++i]);
					if(strcmp(argv[i], "--transfer") == 0)
						isTransfer = true;
				}
				
				if(isTransfer)
					lucy.load_training(0, name);
				else
					lucy.initialize_network(0, epochs, learning);	// Inicialize a rede 0 com 5000 �pocas e 0.5 de aprendizado
				lucy.create_model(0, 2, name, dataset, labels); //"quadrados", "QUADRADO", "TRIANGULO");	// Treinar o modelo 0
			}else{
				printf("Insira o nome ou arquivo do modelo.");
				break;
			}
			continue;
		}
		
		if(strcmp(argv[i], "--pred") == 0){
			lucy.rename(0, argv[++i]);						// Atribua um nome para a rede
			
			if(argv[++i] != NULL){
				lucy.show_response(0, argv[i]);	// Fa�a a previs�o da entrada na rede fignet
			}
			else{
				printf("Forneca uma imagem de entrada!\n");
				break;
			}
			continue;	
		}
		
		if(strcmp(argv[i], "--info") == 0){
			if(argv[++i] != NULL){
				lucy.load_training(0, argv[i]);			// Carrega dados de treinamento
			
				FILE *file;
				if(argv[++i] != NULL){
					// Redireciona stdout para um arquivo
				    file = freopen(argv[i], "w", stdout);
				    if (!file) {
				        perror("Erro ao redirecionar stdout");
				        return 1;
				    }
				}
				
				lucy.show_network(0);					// Apresente as configura��es manuais da rede neural 0
				
				if(argv[i] != NULL){
					// Restaurar stdout (opcional, �til se quiser voltar a imprimir no console)
				    freopen("CON", "w", stdout); // No Linux, use "/dev/tty"
				    printf("As configuracoes foram salvas em '%s'\n", argv[i]);
				}
			}else{
				printf("Forneca o nome do modelo!\n");
				break;	
			}
			continue;
		}
	}
	
	lucy.close_network();							// Fecha todas as redes neurais
	
    return 0;
}

