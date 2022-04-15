/*
 * operaciones_numericas.h
 *
 *  Created on: 12 abr. 2022
 *      Author: DESKTOP
 */

#ifndef OPERACIONES_ARITMETICAS_H_
#define OPERACIONES_ARITMETICAS_H_

float dividir(float dividendo, float divisor);
/// @brief Calcula una division, recibiendo como parametro los valor a dividir
/// @param dividendo = valor que se le dividira por el valor que reciba el 2do parametro
/// @param divisor = este 2do parametro dividira al valor recibido anteriormente
/// @return float = ya que al dividir float por float, resulta un float tambien

float calcularDiferencia(float numero1, float numero2);
/// @brief Calcula la diferencia entre 2 numeros (es indiferente el orden de la resta, siempre va a dar un valor positivo)
/// @param numero1 = valor al que se le restara el valor recibido como 2do parametro
/// @param numero2 = valor que resta al primer valor ingresado
/// @return float = ya que al dividir y multiplicar, el resultado es de tipo float

float aplicarDescuento(float precio, int descuento);
/// @brief Aplica un descuento a un valor determinado
/// @param precio = valor al que se le aplicara un descuento
/// @param descuento = el porcentaje descuento a aplicar
/// @return float = ya que al aplicar un descuento el resultado se convierte a float, mediante (float)

float aplicarAumento(float precio, int aumento);
/// @brief Aplica un aumento a un valor determinado
/// @param precio = valor al que se le aplicara un aumento
/// @param aumento = el porcentaje aumento a aplicar
/// @return float = ya que al aplicar un aumento el resultado se convierte a float, mediante (float)


#endif /* OPERACIONES_ARITMETICAS_H_ */
