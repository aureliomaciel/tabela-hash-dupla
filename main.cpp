#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

const int TAM_NIVEL1 = 10;
const int TOTAL_OBJETOS = 100;
const int TAM_NIVEL2 = TOTAL_OBJETOS / TAM_NIVEL1;

struct Objeto {
    string chave;
    string valor;
};

int hash_nivel1(const string& chave) {
    int soma = 0;
    for (char c : chave) soma += c;
    return soma % TAM_NIVEL1;
}

int hash_nivel2(const string& chave) {
    int soma = 0;
    for (char c : chave) soma += c * 3;
    return soma % TAM_NIVEL2;
}

class TabelaHashDupla {
private:
    vector<vector<list<Objeto>>> tabela;

public:
    TabelaHashDupla() {
        tabela.resize(TAM_NIVEL1, vector<list<Objeto>>(TAM_NIVEL2));
    }

    void inserir(const string& chave, const string& valor) {
        int idx1 = hash_nivel1(chave);
        int idx2 = hash_nivel2(chave);

        for (Objeto& obj : tabela[idx1][idx2]) {
            if (obj.chave == chave) {
                obj.valor = valor;
                return;
            }
        }

        tabela[idx1][idx2].push_back({chave, valor});
    }

    Objeto* buscar(const string& chave) {
        int idx1 = hash_nivel1(chave);
        int idx2 = hash_nivel2(chave);

        for (Objeto& obj : tabela[idx1][idx2]) {
            if (obj.chave == chave) {
                return &obj;
            }
        }

        return nullptr;
    }

    void imprimir() {
        for (int i = 0; i < TAM_NIVEL1; ++i) {
            cout << "Nível 1 [" << i << "]:" << endl;
            for (int j = 0; j < TAM_NIVEL2; ++j) {
                cout << "  Nível 2 [" << j << "]: ";
                for (const Objeto& obj : tabela[i][j]) {
                    cout << obj.chave << " -> ";
                }
                cout << "NULL" << endl;
            }
        }
    }
};

int main() {
    TabelaHashDupla tabela;

    tabela.inserir("Joao", "João");
    tabela.inserir("Marco", "Marco");
    tabela.inserir("Marina", "Marina");
    tabela.inserir("Julia", "Júlia");
    tabela.inserir("Antonio", "Antônio");
    tabela.inserir("Jose", "José");

    string chave = "Marina";
    Objeto* resultado = tabela.buscar(chave);
    if (resultado) {
        cout << "Encontrado: " << resultado->valor << endl;
    } else {
        cout << "Não encontrado: " << chave << endl;
    }

    tabela.imprimir();

    return 0;
}
