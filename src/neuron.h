struct Neuron {
    double bias;
    double* pesos;
    int quantEntradas = 0;

    // Inicializa pesos
    void iniciaPesos(int tamanho){
        quantEntradas = tamanho;
        bias = 0.0;
        pesos = (double*) malloc(sizeof(double) * tamanho);
        srand(21);
        for(int i = 0; i < tamanho; i++)
            pesos[i] = inicializacaoXavier(tamanho);
    }
    // Inicializa��o de Xavier
    double inicializacaoXavier(int tamanho){
    	return ((double) rand() / RAND_MAX) * sqrt(2.0 / (tamanho * 2));
	}

    // Ativa o neur�nio
    double ativar(double* entradas, int quantNeuronios){
        double sum = 0;
        for(int i = 0; i < quantEntradas; i++){
        	sum += entradas[i] * pesos[i];
		}
        sum += bias;
		if(quantNeuronios == 2)
			return sum;
        return sigmoid(sum);
    }

    // Ajusta as sa�das da ativa��o
    double sigmoid(double x){
        return 1 / (1 + exp(-x));
    }
    
    // Fun��o max gen�rica
	double max(double a, double b) {
	    return (a > b) ? a : b;
	}
	
	// Fun��o ReLU utilizando max
	double relu(double x) {
	    return max(0, x);
	}
};
