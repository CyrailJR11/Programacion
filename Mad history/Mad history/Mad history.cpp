#include <iostream>
#include <string>
using namespace std;

// Declaracion de las funciones
string askText(string question);
int askNumber(string question);
float askFloat(string question);
bool askBoolean(string question);
void tellStory(string city, string name, int wakeUpHour, int linesOfCode,
	string robot, string energy, int workDays, string firstWord,
	float hoursOfSleep, bool happy, bool tired, string coreValue, bool useful);

int main() {
	char playAgain;

	do {
		cout << "\n========================================" << endl;
		cout << "  WELCOME TO MAD HISTORY ADVENTURE!" << endl;
		cout << "========================================\n" << endl;
		cout << "Answer the following questions to help create your story.\n\n";

		// Se llaman las funciones para pedir al usuario los datos necesarios
		string city = askText("Enter the name of a small town: ");
		string name = askText("Enter a programmer's name: ");
		int wakeUpHour = askNumber("What hour does " + name + " wake up? (0-23): ");
		int linesOfCode = askNumber("How many lines of code does " + name + " write daily?: ");
		string robot = askText("Enter a name for the robot: ");
		string energy = askText("What type of energy powers the robot? (e.g., solar rays): ");
		int workDays = askNumber("How many days did " + name + " work without rest?: ");
		string firstWord = askText("What was the robot's first word?: ");
		float hoursOfSleep = askFloat("How many hours does " + name + " sleep per night?: ");
		bool happy = askBoolean("Is " + name + " happy with the result? (1 = yes, 0 = no): ");
		bool tired = askBoolean("Is " + name + " tired? (1 = yes, 0 = no): ");
		string coreValue = askText("Enter a core value (e.g., curiosity, patience): ");
		bool useful = askBoolean("Is the technology useful for everyone? (1 = yes, 0 = no): ");

		// se llama a la funcion y se genera la historia
		tellStory(city, name, wakeUpHour, linesOfCode, robot, energy,
			workDays, firstWord, hoursOfSleep, happy, tired, coreValue, useful);

		// pregunta si el usuario quiere jugar otra vez
		cout << "\nDo you want to create another adventure? (y/n): ";
		cin >> playAgain;
		cin.ignore();

	} while (playAgain == 'y' || playAgain == 'Y');

	cout << "\nThank you for playing! Goodbye!\n" << endl;

	return 0;
}


// Funcion que pide al usuario ingresar el texto
// Recibe una pregunta (string) y devuelve un texto (string)
string askText(string question) {
	string answer;
	cout << question;
	getline(cin, answer);
	return answer;
}
// Pide un numero entero 
int askNumber(string question) {
	int number;
	cout << question;
	cin >> number;
	cin.ignore();
	return number;
}
// Permite numeros decimales 
float askFloat(string question) {
	float number;
	cout << question;
	cin >> number;
	cin.ignore();
	return number;
}
// Devuelve tru o false segun la respuesta
bool askBoolean(string question) {
	int answer;
	cout << question;
	cin >> answer;
	cin.ignore();
	return answer == 1;
}
// Genera todos los datos ingresados y genera la historia en orden 
void tellStory(string city, string name, int wakeUpHour, int linesOfCode,
	string robot, string energy, int workDays, string firstWord,
	float hoursOfSleep, bool happy, bool tired, string coreValue, bool useful) {

	// Operacion matematica multiplica las lineas codigo al dia * los dias sin descanso 
	int totalLines = linesOfCode * workDays;
	float productivity = (float)totalLines / workDays;

	cout << "\n\n========================================" << endl;
	cout << "         YOUR STORY BEGINS..." << endl;
	cout << "========================================\n" << endl;

	cout << "In the small town of " << city << ", there lived a young programmer named "
		<< name << ". Every day, he woke up at " << wakeUpHour
		<< ":00, turned on his computer, and wrote at least " << linesOfCode
		<< " lines before breakfast.\n" << endl;

	cout << "One day, he decided to build a robot called " << robot
		<< ", powered by " << energy << ". His goal was to make it capable of learning emotions. After "
		<< workDays << " days without rest, he finally got the robot to say its first word: \""
		<< firstWord << "\".\n" << endl;

	// Bucle pregunta si esta feliz con su trabajo
	if (happy) {
		cout << name << " was incredibly happy with the achievement";
	}
	else { // Si no lo esta 
		cout << name << " was disappointed with the result";
	}

	// Condicion segun el cansancio
	if (tired && hoursOfSleep < 6) {  // pregunta si esta cansado y durmio poco
		cout << ", and extremely exhausted from lack of sleep, but he didn't give up.\n" << endl;
	}
	else if (tired) { // pregunta si esta cansado y durmio bien 
		cout << ", though also a bit tired, but he didn't give up.\n" << endl;
	}
	else { //si no esta cansado
		cout << ", and full of energy to continue!\n" << endl;
	}
	// resumen de los datos introducidos anteriormente 
	cout << "During those " << workDays << " days, " << name << " wrote a total of "
		<< totalLines << " lines of code, with an average productivity of "
		<< productivity << " lines per day.\n" << endl;

	cout << "One night, " << robot << " asked him if humans could also be reprogrammed. "
		<< name << " smiled and replied that the secret wasn't in the code, but in having "
		<< coreValue << ".\n" << endl;

	if (useful) {
		cout << "Since then, " << robot << " and " << name
			<< " worked together, exploring new ways to make technology more useful for everyone." << endl;
	}
	else {
		cout << "Since then, " << robot << " and " << name
			<< " worked together, trying to find ways to improve their creation." << endl;
	}

	cout << "\n========================================" << endl;
	cout << "           THE END" << endl;
	cout << "========================================\n" << endl;
}
