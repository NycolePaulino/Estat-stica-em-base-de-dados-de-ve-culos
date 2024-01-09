
//Declaração de bibliotecas 
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    //declaração de variáveis 
    //float: ponto flutuante, armazenam números decimais.
    float mais_barato, mais_caro, valor, km;

    //string: sequência de caracteres. 
    string modelo, marca, tipo, potencia_do_motor, combustivel, cambio, direcao, cor, portas, placa, placa_mais_barato, placa_mais_caro;

    //int: armazenam números inteiros.
    int contSUV, conthatch, contsedan, contpickup, contpasseio, contvan, contdirecao_cambio, contano, km5anos, ano, carros;

    //ifstream: declaração de leitura de arquivo.
    ifstream arquivo("BD_veiculos.txt");

    //se não existe aquivo
    if (!arquivo.is_open()) {
        //ele pede para que o arquivo seja adicionado
        cerr << "Error! Adicione um arquivo";
        return 1;
    }

    //Declaração dos valores das variáveis 
    //a variável "mais_barato" recebe 10000000.
    mais_barato = 10000000;

    //a variável "mais_caro" recebe 1.
    mais_caro = 1;

    //a variável "valor" recebe 0.
    valor = 0;

    //a variável "km" recebe 0.
    km = 0;

    //a variável "contSUV" recebe 0.
    contSUV = 0;

    //a variável "conthatch" recebe 0.
    conthatch = 0;

    //a variável "contsedan" recebe 0.
    contsedan = 0;

    //a variável "contpickup" recebe 0.
    contpickup = 0;

    //a variável "contpasseio" recebe 0.
    contpasseio = 0;

    //a variável "contvan" recebe 0.
    contvan = 0;

    //a variável "contdireção_cambio" recebe 0.
    contdirecao_cambio = 0;

    //a variável "contano" recebe 0.
    contano = 0;

    //a variável "km5anos" recebe 0.
    km5anos = 0;

    //a variável "ano" recebe 0.
    ano = 0;

    //a variável "carros" recebe 0.
    carros = 0;

    //leitura inicial do arquivo modelo.
    arquivo >> modelo;

    //Iniciação do repita     
    while (modelo != "FIM") {

        //leitura dos arquivos marca, tipo, ano, km, potencia do motor, combustivel, cambio, direcao, cor, portas, placa e valor.
        arquivo >> marca;
        arquivo >> tipo;
        arquivo >> ano;
        arquivo >> km;
        arquivo >> potencia_do_motor;
        arquivo >> combustivel;
        arquivo >> cambio;
        arquivo >> direcao;
        arquivo >> cor;
        arquivo >> portas;
        arquivo >> placa;
        arquivo >> valor;

        //Se o tipo do carro for "Sedan" ou "Sedã" o contsedan recebe mais um.
        if (tipo == "Sedan" || tipo == "Sedã") {
            contsedan++;
        }//se não
        else {
            //Se o carro for tipo "SUV" contSUV recebe mais um.
            if (tipo == "SUV") {
                contSUV++;
            }//se não
            else {
                //Se o carro for tipo "Hatch" conthatch recebe mais um.
                if (tipo == "Hatch") {
                    conthatch++;
                }//se não
                else {
                    //Se o carro for tipo "Pickup" contpickup recebe mais um.
                    if (tipo == "Pick-up") {
                        contpickup++;
                    }//se não
                    else {
                        //Se o tipo do carro for "passeio" contpasseio recebe mais um.
                        if (tipo == "Passeio") {
                            contpasseio++;
                        }//se não
                        else {
                            //Se o tipo do carro for "van" contvan recebe mais im. 
                            contvan++;

                        }

                    }
                }
            }
        }
        //Se o câmbio for Automático e possui direção hidráulica, contdirecao_cambio recebe um.
        if (cambio == "Automático" && direcao == "Hidráulica") {
            contdirecao_cambio++;
        }

        //Se o carro possuir motor de potência 1.0 e for o mais barato já lido, placa_mais_barato recebe o número da placa desse veiculo.
        if (potencia_do_motor == "1.0" && valor < mais_barato) {
            mais_barato = valor;
            placa_mais_barato = placa;
        }

        //Se o valor do veículo for o mais caro lido, e possui direção hidraulica, além de ser flex, placa_mais_caro recebe o número da placa desse veículo.
        if (valor > mais_caro && direcao == "Hidráulica" && combustivel == "Flex") {
            mais_caro = valor;
            placa_mais_caro = placa;
        }

        //Se o carro possuir 5 anos ou mais de fabricação, contano recebe mais 1. 
        if (ano <= 2018) {
            contano++;
            km5anos = km5anos + km;
        }
        //Leitura final do arquivo modelo
        arquivo >> modelo;

        //Contagem de todos os carros lidos (quantidade).
        carros++;
    }

    arquivo.close();

    //aqui mostra a saída dos dados solicitados 
    //Mostra a porcentagem de cada tipo referente aos carros 
    cout << "\tITEM 1-Porcetagem dos tipos de carro: " << endl << "\tSedan:" << (float) contsedan * 100 / carros << "%" << endl;
    //Mostra % de carro tipo "SUV"
    cout << "\tSUV: " << (float) contSUV * 100 / carros << "%" << endl;

    //Mostra % de carro tipo "Hatch" 
    cout << "\tHatch: " << (float) conthatch * 100 / carros << "%" << endl;

    //Mostra a % de carro tipo "Pickup"
    cout << "\tPickup: " << (float) contpickup * 100 / carros << "%" << endl;

    //Mostra a % de carro tipo "Passeio"
    cout << "\tPasseio: " << (float) contpasseio * 100 / carros << "%" << endl;

    //Mostra a % de carro tipo "Van"
    cout << "\tVan: " << (float) contvan * 100 / carros << "%" << endl << endl << "\tITEM 2-";

    //Mostra a % dos veículos com câmbio automático e direção hidráulica 
    cout << "\tPorcentagem de veículos com câmbio automático e direção hidráulica: " << contdirecao_cambio * 100 / carros << "%" << endl << endl;

    //Se no arquivo não possuir carros com a potência 1.0, ele mostra que não existe.
    if (mais_barato == 10000000) {
        cout << "\tITEM 3-Não existe carros com potência 1.0" << endl << endl;
        
    //se não
    } else {
        //Mostra a placa do véiculo mais barato que possui potência 1.0. E também o valor do financiamento com taxa.
        cout << "\tITEM 3-Placa do veículo mais barato com potência 1.0: " << placa_mais_barato << endl << "\tE o seu valor do financiamento com a taxa é: " << mais_barato * (pow(1.0203, 48)) << endl << endl;
    }

    
    //Se no arquivo não possuir carros com combustivel flex, ele mostra que não existe
    if (mais_caro == 1) {
        cout << "\tNão existem carros com combustivel flex";
        
    //se não    
    } else {
        //Mostra a placa do veículo mais caro, que possui combustível flex e também o valor do seguro.
        cout << "\tITEM 4-Placa do veículo mais caro com combustível flex e direção hidráulica: " << placa_mais_caro << endl << "\tE o seu seguro é: " << 0.066 * mais_caro << endl << endl;
    }

    //Se no arquivo não existe carros fabricados há mais de 5 anos, ele mostra que não exise. 
    if (contano == 0) {
        cout << "\tITEM 5-Não existem carros fabricados há mais de 5 anos" << endl << endl;
        
    //se não    
    } else {
        //Mostra a quantidade de carros com mais de 5 anos fabricado.
        cout << "\tITEM 5-Quantidade de carros com mais de 5 anos: " << contano << endl;

        //Mostra a média da kilometragem dos carros com mais de 5 anos.
        cout << "\tMédia da kilometragem dos carros com mais de 5 anos: " << km5anos / contano << endl;
    }

    return 0;
}
