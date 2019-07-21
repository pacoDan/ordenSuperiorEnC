/*
 ============================================================================
 Name        : ejemplo_metodos.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//para las personas al comer engordan mas , su peso es el doble
//para las personas buenas al comer . su peso aumenta a un 10% solamente
//esto ahorra calculos, para tiempos posteriores, ya que para tiempos iniciales se inicializaria el tipo de comportamiento,
// es decir , la asignacion de la funcion como atributo
typedef struct{
	int peso;
	char* nombre;
	bool es_malo;//bueno o malo
	void (*funcion_comer);
}Persona;
void personaMala_comer(Persona* self ){
	self->peso+=self->peso;
}
void personaBuena_comer(Persona* self){
	self->peso=self->peso*1.1;
}
void revisar_conducta(Persona* self){
	self->funcion_comer=(self->es_malo?(*personaMala_comer):(*personaBuena_comer));
//	if(self->es_malo){
//		self->comer=personaMala_comer;
//	}else {
//		self->comer=personaBuena_comer;
//	}
}
void persona_mostrar(Persona p){
	printf(" PERSONA %s con peso %d \n",p.nombre,p.peso);
}
void self_comer(Persona* p){
	revisar_conducta(p);
	void (*comer_)(Persona*) =p->funcion_comer;// malloc(sizeof(void*));
	comer_(p);
}
int main(void) {
	Persona p = {
			.peso=10,
			.nombre="Juan",
			.es_malo=false
	}, juan={
		.peso=10,
		.nombre="Flaco",
		.es_malo=true
	};
	self_comer(&p);
	self_comer(&juan);
	persona_mostrar(p);
	persona_mostrar(juan);
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
