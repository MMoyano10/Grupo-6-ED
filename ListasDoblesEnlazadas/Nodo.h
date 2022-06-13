class Nodo{
	private:
		int valor;
		Nodo *siguiente;
	public:
		/*int getValor(void);
   		void setValor(int newValor);
   		Nodo getSiguiente(void);
   		void setSiguiente(Nodo newSiguiente);
   		Nodo(int _valor, Nodo _siguiente);
   		~Nodo(); */
   		
   		void insertarLista(Nodo *&, int);
   		void buscarLista(Nodo *, int);
   		void eliminarLista(Nodo *&, int);
   		void mostrarLista(Nodo *);
   		bool colaVacia(Nodo *);
   		

};