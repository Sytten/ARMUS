#include "Menu/Menu.h"

void menu(int *jeux)
{
	bool confirmed = false;
	bool internalConfirmed = false;

	while(!confirmed){

		LCD_ClearAndPrint("Bonjour, je propose 3 modes de jeux! Le premier est un mode de m�morisation, le deuxi�me permet d'apprendre la musique et le dernier est un mode libre\n");
		LCD_Printf("Clique sur le premier bouton pour tester ta memoire\n"); // bumper front
		LCD_Printf("Clique sur le deuxi�me bouton pour apprendre une chanson au piano\n"); // bumper rear
		LCD_Printf("Clique sur le troisieme bouton pour jouer librement"); // bumper right


		while (!internalConfirmed)
		{
			if(DIGITALIO_Read(BMP_REAR)) {
				jeux = 1;
				internalConfirmed = true;
			}
			if(DIGITALIO_Read(BMP_FRONT)) {
				jeux = 2;
				internalConfirmed = true;
			}
			if(DIGITALIO_Read(BMP_RIGHT)) {
				jeux = 0;
				internalConfirmed = true;
			}

			THREAD_MSleep(100);
		}
		internalConfirmed = false;
		THREAD_MSleep(500);

		LCD_ClearAndPrint("Il reste seulement � confimer ton choix\n");

		if (jeux == 0)
			LCD_ClearAndPrint("Tu d�sire jouer en mode libre\n");

		else if (jeux == 1)
			LCD_ClearAndPrint("Tu d�sire pratiquer ta m�moire\n");

		else if (jeux == 2)
			LCD_ClearAndPrint("Tu d�sire apprendre le piano\n");


		LCD_Printf("C'est ok?\n");
		LCD_Printf("Oui, premier bouton\n");
		LCD_Printf("Non, deuxieme bouton\n");

		while(!internalConfirmed)
		{
			if(DIGITALIO_Read(BMP_RIGHT)) {
				internalConfirmed = true;
				confirmed = true;
			}
			if(DIGITALIO_Read(BMP_LEFT)) {
				internalConfirmed = true;
				confirmed = false;
			}
			THREAD_MSleep(100);
		}
		internalConfirmed = false;
		THREAD_MSleep(500);
	}

}