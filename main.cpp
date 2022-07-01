#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::endl;

const char stop = '0';

namespace Pairs{
    class Name_pairs{
    public:
            void read_names();
            void read_ages();
            void sort_();
            vector<string> get_name()const;
            vector<double> get_age()const;
    private:
            vector<string>name;
            vector<double>age;
    };
}

Pairs::Name_pairs& p1()           // Criação de um objeto para acessar os membros da classe. Para evitar a criação de uma
{                                 // variável global, a boa prática da engenharia de software é criar uma função que retorna
    static Pairs::Name_pairs a;   // esse objeto. Declara-se o objeto dentro da função, como static para não ser destruído
    return a;                     // ao término da execução da função, de modo que dure até o fim da execução do programa,
}                                // e acumule todas as modificações sofridas resultantes do elemento pass-by-value.

vector<string> Pairs::Name_pairs::get_name()const //nonmodifying operation: não modifica o objeto, podendo ser chamada
{                                                 //por objetos declarados constantes. Modifying operations não podem
    return name;                                  //ser chamadas por objetos declarados constantes.
}

vector<double> Pairs::Name_pairs::get_age()const //nonmodifying operation
{
    return age;
}

bool operator==(const Pairs::Name_pairs& a,const  Pairs::Name_pairs& b)
{
    return a.get_name()==b.get_name()&&
           a.get_age()==b.get_age();
}

bool operator!=(const Pairs::Name_pairs& a, const Pairs::Name_pairs& b)
{
    return !(a==b);
}

void Pairs::Name_pairs::read_names()
{
    string s;
    if(cin>>s&&isalpha(s[0])){
        p1().name.push_back(s); // O objeto sem acesso aos private members de uma classe, pode acessar estes private members
    }                           // desde que esteja tentando acessá-los dentro do escopo de uma member-function. Uma função
    else{                       // que retorna um objeto de uma classe, pode retornar diretamente os membros da classe do
        cout << "Wrong input!\n";   // objeto, através da notação colocando um ponto seguindo a função, e seguindo o ponto o
        cout << "Enter a name: ";   // membro da classe que se quer acessar/retornar para sofrer a modificação/operação.
        p1().read_names();
    }
}

void Pairs::Name_pairs::read_ages()
{
    char ch;
    double d;
    if(cin>>ch&&isdigit(ch)){
        cin.putback(ch);
        cin >> d;
        p1().age.push_back(d);
    }
    else{
        cout << "Wrong input!" << endl;
        string s;
        getline(cin, s);
        cout << "Enter a age: ";
        p1().read_ages();
    }
}

void print()
{
    for(int i=0; i<p1().get_name().size(); ++i){
        cout << p1().get_name()[i] << '\t' << p1().get_age()[i] << endl; // A função retorna o objeto, daí já chamo uma
    }                                                                    // member-function do objeto que retorna um
}                                                                        // data-member, que no caso é um vector.
                                                                         // Daí já uso Brackets para definir a posição do
void Pairs::Name_pairs::sort_()                                          // elemento dentro do vector a ser retornado.
{
    vector<string>name3 {p1().name};
    vector<double>age4;
    sort(p1().name.begin(), p1().name.end());
    for(int i=0; i<p1().name.size(); ++i){
        for(int j=0; j<name3.size(); ++j){
            if(p1().name[i]==name3[j])
                age4.push_back(p1().age[j]);
        }
    }
    p1().age = age4;
}

void get_pair()
{
    while(true){
        char ch;
        cout << "Enter a name: ";
        cin >> ch;                //  A operação "cin >>" automaticamente coloca uma new line '\n' após um input externo.
        if(ch==stop)break;        //  Caso ocorra um "cin.putback(ch)", o "cin>>" para "reinputar" ch não resulta em '\n'.
        cin.putback(ch);
        p1().read_names();
        cout << "Enter a age: ";
        p1().read_ages();

    }
}

enum class Month{
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

Month operator++(Month& m)
{
    m = (m==Month::dec) ? Month::jan : Month(int(m)+1);
    return m;
}

Month m;

int main()
{
    get_pair();
    print();
    p1().sort_();
    print();
}
