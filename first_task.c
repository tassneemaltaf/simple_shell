#include <stdio.h>
/**
 * protein_amount - gives amount of protein intake based on weight
 * Return: returns nothing
 */
void protein_amount(void)
{
	int weight;
	int total_grams;

	printf("Enter you weight: ");
	scanf("%d", &weight);
	total_grams = weight * 0.8;
	printf("Your total protein intake should be %dg per day", total_grams);
}
