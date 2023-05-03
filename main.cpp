#include <iostream>

using namespace std;

class SocioClub{
    private:
        int NumeroSocio;
        string NombreSocio;
        string Domicilio;
        int AnioIngreso;
    public:
        SocioClub(){};
        friend std::ostream & operator<<(std::ostream &O, SocioClub &x){
            O<<"\n Numero de socio: "<<x.NumeroSocio;
            O<<"\n Nombre de socio: "<<x.NombreSocio;
            O<<"\n Domicilio de socio: "<<x.Domicilio;
            O<<"\n Anio de ingreso: "<<x.AnioIngreso;
            return O;
        }
        friend std::istream & operator>>(std::istream &O, SocioClub &x){
            std::cout<<"\n Numero de socio: ";
            O>>x.NumeroSocio;
            std::cout<<" Nombre de socio: ";
            O>>x.NombreSocio;
            std::cout<<" Domicilio de socio: ";
            O>>x.Domicilio;
            std::cout<<" Anio de ingreso: ";
            O>>x.AnioIngreso;
            return O;
        }
        bool operator==(SocioClub &x){
        return (NumeroSocio==x.NumeroSocio && NombreSocio==x.NombreSocio && Domicilio==x.Domicilio && AnioIngreso==x.AnioIngreso);
        }
        bool operator!=(SocioClub &x){
        return (NumeroSocio!=x.NumeroSocio && NombreSocio!=x.NombreSocio && Domicilio!=x.Domicilio && AnioIngreso!=x.AnioIngreso);
        }
        bool operator<(SocioClub &x){
            return (NumeroSocio<x.NumeroSocio);
        }
        bool operator>(SocioClub &x){
            return (NumeroSocio>x.NumeroSocio);
        }
        bool operator<=(SocioClub &x){
            return (NumeroSocio<=x.NumeroSocio);
        }
        bool operator>=(SocioClub &x){
            return (NumeroSocio>=x.NumeroSocio);
        }
        void setNombre(string);
        void setDomicilio(string);
};

template<class T>
class LSLSE;

template<class T>
class node{
    private:
        SocioClub datos;
        node<T>* sig;
    public:
        node():sig(nullptr){};
        T getData(){
            return datos;
        }
        friend class LSLSE<T>;
};

template<class T>
class LSLSE{
    private:
        node<T>* lista;
    public:
        LSLSE():lista(nullptr){};
        bool vacia()const;
        node<T>* ultimo()const;
        node<T>* primero()const;
        node<T>* anterior(node<T>* pos)const;
        void insertar(node<T>* pos, SocioClub datos);
        bool eliminar(node<T>* pos);
        void imprimir()const;
        node<T>* localiza(SocioClub datos);
        node <T>* recupera(T elem)const;
        void ordenamiento();
        void contador();
};

void SocioClub::setNombre(string n){
    NombreSocio=n;
}

void SocioClub::setDomicilio(string d){
    Domicilio=d;
}

template<class T>
node<T>* LSLSE<T>::localiza(SocioClub datos){
     node<T>* aux=lista;
     while(aux!=nullptr && aux->datos!=datos){
            aux=aux->sig;
     }
     return aux;
}

template<class T>
node<T>* LSLSE<T>::recupera(T elem)const{
    node<T>* aux=lista;
    while(aux!=nullptr && aux->datos!=elem){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
void LSLSE<T>::imprimir()const{
    if(vacia())
        cout<<"\nLista se encuentra vacia. . .\n\n";
    node<T>* aux=lista;
    while(aux!=nullptr){
        std::cout<<aux->datos<<endl;
        aux=aux->sig;
    }
}

template<class T>
bool LSLSE<T>::eliminar(node<T>* pos){
    if(vacia() || pos==nullptr){
        cout<<"\nSocio proporcionado no existe. . .\n\n";
        return false;
    }
    if(pos==lista){
        lista=lista->sig;
    }
    else{
        anterior(pos)->sig=pos->sig;
    }
    delete pos;
    cout<<"\nSocio eliminado correctamente. . .\n\n";
    return true;
}

template<class T>
void LSLSE<T>::insertar(node<T>* pos, SocioClub elem){
    node<T>* aux= new node<T>;
    aux->datos=elem;
    if(pos==nullptr){
        aux->sig=lista;
        lista=aux;
    }
    else{
        aux->sig=pos->sig;
        pos->sig=aux;
    }

}

template<class T>
node<T>* LSLSE<T>::anterior(node<T>* pos)const{
    if(vacia() || pos==nullptr){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux!=nullptr && aux->sig!=pos){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
node<T>* LSLSE<T>::primero()const{
    if(vacia()){
        return nullptr;
    }
    return lista;
}

template<class T>
node<T>* LSLSE<T>::ultimo()const{
    if(vacia()){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux->sig!=nullptr){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
bool LSLSE<T>::vacia()const{
    if(lista==nullptr)
        return true;
    return false;
}

template<class T>
void LSLSE<T>::ordenamiento()
{
    node<T>* aux = lista, *temp = nullptr;
    SocioClub t;
    if (lista == nullptr) {
        return;
    }else {
        while (aux != NULL) {
            temp = aux->sig;
            while (temp != NULL) {
            if (aux->datos > temp->datos) {
                t = aux->datos;
                aux->datos = temp->datos;
                temp->datos = t;
            }
            temp = temp->sig;
        }
        aux = aux->sig;
        }
    }
}

template<class T>
void LSLSE<T>::contador(){
    int i=1;
    if(lista==nullptr){
        cout<<"\nLa lista se encuentra vacia. . .\n"<<endl;
    }
    else{
    node<T>* aux=lista;
    while(aux->sig!=nullptr){
        aux=aux->sig;
        i++;
    }
    cout<<"\nNumero de socios registrados: "<<i<<endl<<endl;
    }
}

void menu(){
    std::cout<<"------Menu Socios------"<<std::endl;
    std::cout<<"1. Registrar nuevo socio"<<std::endl;
    std::cout<<"2. Dar de baja socio"<<std::endl;
    std::cout<<"3. Reporte de datos de socios"<<std::endl;
    std::cout<<"4. Busqueda de socio"<<std::endl;
    std::cout<<"5. Total socios registrados"<<std::endl;
    std::cout<<"6. Salir"<<std::endl;
    std::cout<<"Opcion: ";
}

int main()
{
    LSLSE<SocioClub> milista;
    SocioClub socio,elem,elem1;
    char temp[30];
    int opc;
    do{
        system("cls");
        menu();
        cin>>opc;
        switch(opc){
            case 1:
                cout<<"\nRegistrar datos de nuevo socio: \n";
                cin>>socio;
                milista.insertar(milista.ultimo(), socio);
                milista.ordenamiento();
                cout<<"\nSocio agregado correctamente. . .\n\n";
                system("pause");
                break;
            case 2:
                if(milista.vacia()){
                    cout<<"\nLa lista se encuentra vacia. . .\n\n";
                }
                else{
                cout<<"\nDatos de socio a dar de baja: \n";
                cin>>socio;
                milista.eliminar(milista.localiza(socio));

                }
                system("pause");
                break;
            case 3:
                cout<<"\nDatos de socios registrados: "<<endl;
                milista.imprimir();
                cout<<"\n";
                system("pause");
                break;
            case 4:
                if(!milista.vacia()){
                    std::cout<<"\nProporcione los datos de socio a buscar\n"<<std::endl;
                    std::cout<<" Nombre de socio: ";
                    std::cin>>temp;
                    elem.setNombre(temp);
                    std::cout<<" Domicilio de socio: ";
                    std::cin>>temp;
                    elem.setDomicilio(temp);
                    if(milista.recupera(elem)){
                        elem1=milista.recupera(elem)->getData();
                        std::cout<<"\nSocio encontrado\n"<<elem1<<std::endl<<std::endl;
                    }
                    else{
                        std::cout<<"\nSocio no encontrado\n"<<std::endl;
                    }
                }else{
                    std::cout<<"\nLa lista se encuentra vacia. . .\n"<<std::endl;
                }
                system("pause");
                break;

            case 5:
                milista.contador();
                system("pause");
                break;
            default:
                cout<<"\nSaliendo . . .\n";
        }
    }
    while(opc!=6);
    return 0;
}
