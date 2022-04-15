/*
 * operaciones_numericas.c
 *
 *  Created on: 12 abr. 2022
 *      Author: DESKTOP
 */

float dividir(float dividendo, float divisor){

	float resultado;

	resultado = dividendo/divisor;

	return resultado;
}

float calcularDiferencia(float valor1, float valor2){

	float diferencia;

	diferencia = valor1 - valor2;
	if(diferencia < 0)
	{
		diferencia = diferencia + (diferencia*(-2));
	}
	return diferencia;
}
float aplicarDescuento(float precio, int descuento){

	float precioDescontado;

	precioDescontado = precio - (precio * descuento/100);

	return precioDescontado;

}

float aplicarAumento(float precio, int aumento){

	float precioAumentado;

	precioAumentado = precio + (precio * aumento/100);

	return precioAumentado;
}
