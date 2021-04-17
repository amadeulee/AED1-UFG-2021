#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

// A fazer:
// Suportar numeros com mais de 1 algarismo
// Conversão string->int
int main()
{
	stack<char> operadores;	// Pilha de Operadores
	stack<char> saida;		// Pilha de saída
	stack<char> temp;		// Pilha para inverter
	stack<char> resposta;	// Pilha da resposta

	string comando;

	cout << "=>";
	cin >> comando;

	// Algoritmo "Shunting Yard"
	// fonte: http://en.wikipedia.org/wiki/Shunting-yard_algorithm
	for(int i=0; i<comando.size(); i++)
	{
		switch(comando[i])
		{
		case '*': case '+': case '-': case '/': case'(': 
			operadores.push(comando[i]);
			break;

		case ')':
			while(operadores.top() != '(')
			{
				saida.push(operadores.top());
				operadores.pop();
			}
			operadores.pop();
			break;

		default:
			saida.push(comando[i]);
			break;
		}
	}

	while(!operadores.empty())
	{
		saida.push(operadores.top());
		operadores.pop();
	}

	// Inverte a saída para aparecer na ordem certa
	while(!saida.empty())
	{
		temp.push(saida.top());
		saida.pop();
	}

	/* while(!temp.empty())
	{
		cout << temp.top() << " ";
		temp.pop();
	} */
	
	while(!temp.empty())
	{
		// Adição; o resto segue o mesmo padrão
		if(temp.top() == '+')
		{
			stringstream res;
			int a = resposta.top() - '0'; // Gambiarra para converter de char para int
			resposta.pop();
			int b = resposta.top() - '0';
			resposta.pop();
			res << b+a;
			cout << "B+A=" << b+a << endl;
			resposta.push(b+a);
			cout << "Resposta.top=" << resposta.top() << endl;
		} else {
			resposta.push(temp.top());
		}
		temp.pop();
	}
	system("pause");
	return 0;
}