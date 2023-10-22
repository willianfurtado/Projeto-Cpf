#include <stdio.h>

int calcDigito1(char cpf[]) { //Função que calculará o primeiro dígito do CPF
    int peso = 10; //Começa com 11 pois é o segundo dígito e ocupa 11ª posição
    int soma = 0;
    int resto; //Variável que irá receber o cálculo do resto para verificar o dígito 
    int digito; //Variável que irá armazenar o dígito depois de ser calculado

    //Nesta estrutura de repetição será calculada o primeiro dígito verificad1or do CPF
    for(int i = 0; i < 9; i++){
        soma += (cpf[i] - '0') * peso;
        peso--;
    }

    resto = soma % 11; //Será feito o cálculo do resto de divisão da soma dos produtos por 11

    if(resto < 2) { // Se o resto for menor que 2, digito será 0
        digito = 0;
    }
    else { //Senão, o primeiro dígito será o resultado de 11 pelo resto calculado
        digito = 11 - resto;
    }

    return digito; //Retorna o primeiro dígito
}

int calcDigito2(char cpf[]) { //Função que calculará o segundo dígito do CPF
    int peso = 11; //Começa com 11 pois é o segundo dígito e ocupa 11ª posição
    int soma = 0;
    int resto; //Variável que irá receber o cálculo do resto para verificar o dígito 
    int digito; //Variável que irá armazenar o dígito depois de ser calculado

    //Nesta estrutura de repetição será calculada o segundo dígito verificador do CPF
    for(int i = 0; i < 10; i++) {
        soma += (cpf[i] - '0') * peso;
        peso--;
    }

    resto = soma % 11;  //Será feito o cálculo do resto de divisão da soma dos produtos por 11

    if(resto < 2) { //Se o resto for menor que 2, digito será 0
        digito = 0;
    }
    else { //Senão, o primeiro dígito será o resultado de 11 pelo resto calculado
        digito = 11 - resto;
    }

    return digito;
}

int main() {
    char cpf[11]; //Este vetor tem 11 posições a partir da quantidade de números de um CPF completo
    char cpf_completo[12]; // O vetor terá 12 posições para ser adicionado o espço para o caractere nulo
    int dig_1, dig_2;

    printf("Digite os 9 primeiros dígitos do CPF: "); //Solicitamos os 9 primeiros digitos do CPF
    scanf("%9s", &cpf);

    dig_1 = calcDigito1(cpf);
    dig_2 = calcDigito2(cpf);

    //Aqui é copiado os 9 primeiros dígitos para o CPF completo que irá ser mostrado futuramente
    for(int i = 0; i < 9; i++) {
        cpf_completo[i] = cpf[i];
    }

    //Neste bloco de código Adiciona os dígitos verificadores ao CPF completo
    cpf_completo[9] = dig_1 + '0'; //Aqui é adicionado o primeiro digito verificador
    cpf_completo[10] = dig_2 + '0'; //Aqui é adicionado o segundo digito verificador

    cpf_completo[11] = '\0'; // Adicionamos o caractere nulo para finalizar a string do CPF

    printf("CPF completo: %s\n", cpf_completo); //Aqui exibimos o cpf completo

    return 0;
}