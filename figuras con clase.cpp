//william alfredo vasquez flores
//VF18003
#include<iostream>//libreria estandar
#include <math.h>//para hacer calculos matematicos
//cuerpo del programa
using namespace std;

class Figura{//se declara la clase figura
	private:
		float base;
		float altura;
	
	public:
		//Pueden haber varios constructores gracias al polimorfismo
		Figura(){ //inicializa  las variables en 0
			this->base = 0;
			this->altura = 0;
		}
		
		Figura(float b, float h){ //inicializa las variables en un valor espeficico
			this->base = b;
			this->altura = h;
		}
		
		//No se puede tener dos constructores que reciban la misma cantidad de argumentos y el mismo tipo de dato 
		~Figura(){
			
		}
		
		//se necesita crear un set y get para cada propiedad, ademas de las funciones area y perimetro
		void setBase(float b){
			this->base = b;
		}
		float getBase(){
			return this->base;
		}
		
		void setAltura(float h){
			this->altura = h;
		}
		float getAltura(){
			return this->altura;
		}
		
		virtual float area() = 0;//se iguala a 0 para definir la funcion
		//virtual significa que luego se puede sobreescribir/redefinir sobre la funcion.
		virtual float perimetro() = 0;
			
};

class Color{
	public:
		void colorear(){
			cout << "Estoy pintando\n\n\n\n";
		}
};

class Rectangulo:public Figura, public Color{
	public:
		float area(){
			return getAltura()*getBase();
		}
		
		float perimetro(){
			return ((2*getAltura())+(2*getBase()));
		}
		
		void imprimirR(){ //imprimira el rectangulo
			cout << endl;
			for(int i = 0; i < getAltura(); i++){
				
				for(int j = 0; j < getBase(); j++){
						if(i == 0 or j == 0 or j == getAltura()+1 or i == getAltura()-1){
							cout << " * ";	
						}else{
							cout << "   ";
						}
							
				}
				cout << endl;
			}
			cout << endl;
		}
		
};

class Cuadro:public Figura, public Color{
	public:
		float area(){
			return getAltura()*getBase();
		}
		
		float perimetro(){
			return ((2*getAltura())+(2*getBase()));
		}
		
		void imprimirR(){ //imprimira el rectangulo
			cout << endl;
			for(int i = 0; i < getAltura(); i++){
				
				for(int j = 0; j < getBase(); j++){
						if(i == 0 or j == 0 or j == getAltura()-1 or i == getAltura()-1){
							cout << "* ";	
						}else{
							cout << "  ";
						}
							
				}
				cout << endl;
			}
			cout << endl;
		}
		
};

class Triangulo:public Figura, public Color{
	private:
		float lado1;
		float lado2;
	public:
		
		void setLado1(float l){
			this->lado1 = l;
		}
		float getLado1(){
			return this->lado1;
		}
		
		void setLado2(float l){
			this->lado2 = l;
		}
		float getLado2(){
			return this->lado2;
		}
		
		float area(){
			float semi = (getBase() + getLado1() + getLado2())/2;
			float area = sqrt(semi*(semi-lado1)*(semi-lado2)*(semi-getBase()));
			return area;
		}
		
		float perimetro(){
			return (getLado1()+getBase()+getLado2());
		}
		
		void imprimirR(){ //imprimira el rectangulo
			cout << endl;
			for(int i = 0; i < getBase(); i++){
				int x = getBase()-i;
				for(int j = 0; i >= j; j++){
					
						while(x != 0){
							cout << " ";
							x--;
						}
						cout << "* ";				
				}
				cout << endl;
			}

		}
		
};

class Principal{
	public:
		Principal(){
			Rectangulo *r = new Rectangulo();
			Cuadro *c = new Cuadro();
			Triangulo *t = new Triangulo();
			
			r->setAltura(4);
			r->setBase(6);		
			cout << "base: " << r->getBase() << "\naltura: " << r->getAltura() << endl;//cout << "___" << r->imprimirR();
			cout << "area: " <<  r->area() << endl << "perimetro: " << r->perimetro() << endl; 
			r->imprimirR();
			r->colorear();//Proviene desde colorear 
				
			c->setBase(6);
			c->setAltura(6);
			cout << "base: " << c->getBase() << "\naltura: " << c->getAltura() << endl;
			cout << "area: " <<  c->area() << endl << "perimetro: " << c->perimetro() << endl; 
			c->imprimirR();
			c->colorear();
			
			t->setBase(6);
			t->setLado1(4);
			t->setLado2(4);
			cout << "base: " << t->getBase() << "\nlado 1: " << t->getLado1() << "\nlado 2: " << t->getLado2() << endl;
			cout << "area: " <<  t->area() << endl << "perimetro: " << t ->perimetro() << endl; 
			t->imprimirR();
			t->colorear();
			
			}
};

int main(){

/*	Figura *t = new Figura(); //instanciar a 0
	Figura *d = new Figura(2,3);//instanciar a 2 y 3
	
	t->setBase(4); //solo puede acceder a los metodos publicos, no puede acceder directamente a los datos altura y base.
	t->setAltura(2);
	
	cout << t->getBase() << "--" << t->getAltura() << endl;
	cout << d->getBase() << "--" << d->getAltura() << endl << endl << endl;
*/	
	
	
	/*Rectangulo *r = new Rectangulo();
	
	r->setAltura(4);
	r->setBase(6);
	
	cout << "base: " << r->getBase() << "\naltura: " << r->getAltura() << endl;//cout << "___" << r->imprimirR();
	
	cout << "area: " <<  r->area() << endl << "perimetro: " << r->perimetro() << endl; 
	
	r->imprimirR();*/
	
	
	Principal *pro = new Principal(); //es una relacion de dependencia
	
	cout << "Presione cualquier tecla para continuar...";
	cin.get();
	return 0;
}
