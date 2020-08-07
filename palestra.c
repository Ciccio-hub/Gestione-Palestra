#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Strutture dati

typedef struct registrazione {
	char nome[30];
	char cognome[30];
	char password[30];
}registrazione;

struct nodo_reg {
	registrazione reg;
	struct nodo_reg *next;
};

typedef struct identificativo {
	char email[30];
	struct nodo_reg *testa;
}identificativo;

struct nodo_id {
	identificativo id;
	struct nodo_id *next;
};

typedef struct turno {
	int GG;
	int MM;
	int AA;
	float inizio_turno;
	float fine_turno;
	int prenotazioni;
	int max;
	struct nodo_id *testa_i;
}turno;

struct nodo_t {
	turno turn;
	struct nodo_t *next;
};

//Prototipi delle funzioni

void crea_lista_i(struct nodo_id **head);
void crea_lista_t(struct nodo_t **head);
int login_amministratore();
int login_utente(struct nodo_id *head);
void listaordinata(struct nodo_id **head, char nome[], char cognome[], char password[], char email[]);
void importa(struct nodo_id **head);
void inserimento_ordinato(struct nodo_reg **head);
void registrazione_utenti(struct nodo_id **head);
void ricerca_utenti(struct nodo_id *head);
void scrivi_su_file(struct nodo_id *head);
void visualizza(struct nodo_id *head);
void inserimento_testa(struct nodo_t **head, int GG, int MM, int AA, float inizio_turno, float fine_turno, int prenotazioni, int max);
void importa_turni(struct nodo_t **head);
void visualizza_turni(struct nodo_t *head);
void inserimento_turno(struct nodo_t **head);
void scrivi_turni_file(struct nodo_t *head);
void modifica_turni(struct nodo_t *head);
void cancella_turno(struct nodo_t **head);
void visualizza_turni_disponibili(struct nodo_t *head);
void inserimento_in_turno(struct nodo_t *head);
void rimozione_da_turno(struct nodo_t *head);

//Main

int main() {
	char nome[30], cognome[30], password[30], email[30];
	int scelta;
	int scelta_utente;
	int scelta_utente_m;
	int scelta_amministratore;
	int valore_restituito_a;
	int valore_restituito_u;
	struct nodo_id *head;
	struct nodo_t *testa;

	crea_lista_i(&head);
	crea_lista_t(&testa);
	importa(&head);
//	visualizza(head);
	importa_turni(&testa);
//	visualizza_turni(testa);

	printf("***MENU PRINCIPALE***\n");
	printf("[1] Amministratore\n");
	printf("[2] Utente\n");
	printf("[0] Esci\n");
	printf("Inserisci la tua scelta\n");
	scanf("%d", &scelta);
	while(scelta<0 || scelta>2) {
	printf("Errore!! La scelta inserita non è valita\n");
	printf("Inserisci nuova scelta\n");
	scanf("%d", &scelta);
	}
		switch(scelta) {
			case 1:
				system("clear");
				valore_restituito_a = login_amministratore();
				if(valore_restituito_a == 1) {
				printf("Benvenuto all'interno del menu amministratore\n");
				printf("***MENU AMMINISTRATORE***\n");
				printf("[1] Lista e ricerca di utenti della palestra\n");
				printf("[2] Inserimento di turni della palestra\n");
				printf("[3] Modifica di turni della palestra\n");
				printf("[4] Cancellazione di turni della palestra\n");
				printf("[0] Logout\n");
				printf("Inserisci la tua scelta\n");
				scanf("%d", &scelta_amministratore);
				while(scelta_amministratore<0 || scelta_amministratore>4) {
				printf("Errore!! La scelta inserita non è valita\n");
				printf("Inserisci nuova scelta\n");
				scanf("%d", &scelta_amministratore);
				}
					switch(scelta_amministratore) {
						case 1:
				                        system("clear");
							ricerca_utenti(head);
							break;
						case 2:
							system("clear");
							inserimento_turno(&testa);
                                                        visualizza_turni(testa);
							scrivi_turni_file(testa);
							break;
						case 3:
							system("clear");
							modifica_turni(testa);
							break;
						case 4:
							system("clear");
							cancella_turno(&testa);
							visualizza_turni(testa);
							scrivi_turni_file(testa);
							importa_turni(&testa);
							break;
						case 0:
							return 0;
					}
				break;
				} else {
			case 2:
				system("clear");
				printf("***SCELTA UTENTE***\n");
				printf("[1] Login Utente\n");
				printf("[2] Registrazione Utente\n");
				printf("Inserisci la tua scelta\n");
				scanf("%d", &scelta_utente);
				while(scelta_utente<1 || scelta_utente>2) {
				printf("Errore!! La scelta inserita è errata!!\n");
				printf("Inserisci nuova scelta\n");
				scanf("%d", &scelta_utente);
				}
					switch(scelta_utente) {
						case 1:
							system("clear");
							valore_restituito_u = login_utente(head);
							if(valore_restituito_u == 1) {
							printf("I dati inseriti sono corretti!! Benvenuto nel menu utente\n");
							printf("***MENU UTENTE***\n");
							printf("[1] Lista dei turni disponibili\n");
							printf("[2] Inserimento in un turno\n");
							printf("[3] Rimozione da un turno\n");
							printf("[0] Logout\n");
							printf("Inserisci la tua scelta\n");
							scanf("%d", &scelta_utente_m);
							while(scelta_utente_m<0 || scelta_utente_m >3) {
				                        printf("Errore!! La scelta inserita è errata!!\n");
                      				        printf("Inserisci nuova scelta\n");
                        			        scanf("%d", &scelta_utente_m);
							}
								switch(scelta_utente_m) {
									case 1:
										system("clear");
									        visualizza_turni_disponibili(testa);
										break;
									case 2:
										system("clear");
										inserimento_in_turno(testa);
		                                                       		visualizza_turni(testa);
                                                                                scrivi_turni_file(testa);
										break;
									case 3:
										system("clear");
										rimozione_da_turno(testa);
                                                                                visualizza_turni(testa);
                                                                                scrivi_turni_file(testa);
										break;
									case 0:
										return 0;
								}
							break;
							} else {
						case 2:
							system("clear");
							printf("Per accedere al menu utente è necessario registrarsi!!\n");
							printf("Per effettuare la registrazione inserire i dati richiesti\n");
							registrazione_utenti(&head);
							scrivi_su_file(head);
						        visualizza(head);
							break;
							}
					}
				break;
				}
			case 0:
				return 0;
		}
}

//Corpo delle funzioni
void crea_lista_i(struct nodo_id **head) {
	*head = NULL;
}

void crea_lista_t(struct nodo_t **head) {
	*head = NULL;
}

int login_amministratore() {
	char email_amministratore[30] = {'a','m','m','i','n','i','s','t','r','a','t','o','r','e','@','g','m','a','i','l','.','c','o','m','\0'};
	char password_amministratore[30] = {'a','m','m','i','n','i','s','t','r','a','t','o','r','e','\0'};
	char email[30];
	char password[30];

	printf("Inserisci l'email\n");
	scanf("%s", email);
	printf("Inserisci la password\n");
	scanf("%s", password);

	if((strcmp(email, email_amministratore)==0) && (strcmp(password, password_amministratore)==0)) {
	printf("I dati inseriti sono corretti!!\n");
	return 1;
	} else {
	printf("I dati inseriti sono errati!!\n");
	return 0;
	}
}

int login_utente(struct nodo_id *head) {
	char email_utente[30];
	char password_utente[30];
	struct nodo_id *p;
	p = head;

	printf("Inserisci l'email\n");
	scanf("%s", email_utente);
	printf("Inserisci la password\n");
	scanf("%s", password_utente);

	while((p!=NULL)) {
	if(strcmp(p->id.email, email_utente)==0 && (strcmp(p->id.testa->reg.password, password_utente)==0)) {
	printf("Giusto\n");
	return 1;
	}
	p = p->next;
	}
	if(p == NULL) {
	printf("I dati inseriti sono errati!!\n");
	return 0;
	}
}

void listaordinata(struct nodo_id **head, char nome[], char cognome[], char password[], char email[]) {
	struct nodo_id *p = NULL;
	struct nodo_reg *tmp = NULL;
	struct nodo_id *curr = *head, *precedente = *head;
	p = (struct nodo_id *)malloc(sizeof(struct nodo_id));
	tmp = (struct nodo_reg *)malloc(sizeof(struct nodo_reg));
	p->id.testa = tmp;
	strcpy(p->id.email, email);
	strcpy(tmp->reg.nome, nome);
	strcpy(tmp->reg.cognome, cognome);
	strcpy(tmp->reg.password, password);
	p->id.testa->next = NULL;

	while((curr!=NULL) && ((strcmp(curr->id.email, email) == 0) && (strcmp(curr->id.email, precedente->id.email)>0))) {
	precedente = curr;
	curr = curr->next;
	}
	if(curr == *head)
		*head = p;
	else
		precedente->next = p;
	p->next = curr;
}

void importa(struct nodo_id **head) {
	char nome[30], cognome[30], password[30], email[30];
	FILE *f;

	f = fopen("utenti.txt","r");
	if(f == NULL) {
	printf("La lista è vuota\n");
	return;
	}

	while(fscanf(f,"%30s %30s %30s %30s", nome, cognome, password, email)!=EOF) {
	listaordinata(head, nome, cognome, password, email);
	}
	fclose(f);
}

void visualizza(struct nodo_id *head) {
	struct nodo_id *p;
	p = head;

	if(p == NULL) {
	printf("La lista è vuota\n");
	return;
	}

	while(p!=NULL) {
	printf("%s %s %s %s\n", p->id.testa->reg.nome, p->id.testa->reg.cognome, p->id.testa->reg.password, p->id.email);
	p = p->next;
	}
}

void ricerca_utenti(struct nodo_id *head) {
	char email[30];
	struct nodo_id *p;
	p = head;

	printf("Inserisci l'email dell'utente da cercare\n");
	scanf("%s", email);

	while((p!=NULL) && (strcmp(p->id.email, email)!=0)) {
	p = p->next;
	}
	if(p==NULL) {
	printf("L'email inserita non è presente\n");
	} else {
	printf("L'utente è stato trovato\n");
	printf("Nome: %s\nCognome: %s\n", p->id.testa->reg.nome, p->id.testa->reg.cognome);
	}
}

void inserimento_utenti(struct nodo_reg **head) {
	struct nodo_reg *p;
	p = (struct nodo_reg *)malloc(sizeof(struct nodo_reg));

	printf("Inserisci nome\n");
	scanf("%s", p->reg.nome);
	printf("Inserisci cognome\n");
	scanf("%s", p->reg.cognome);
	printf("Inserisci password\n");
	scanf("%s", p->reg.password);

	p->next = *head;
	*head = p;
}

void registrazione_utenti(struct nodo_id **head) {
	struct nodo_id *p;
	struct nodo_reg *tmp;
	struct nodo_id *curr = *head, *precedente = *head;
	p = (struct nodo_id *)malloc(sizeof(struct nodo_id));

	printf("Inserisci email\n");
	scanf("%s", p->id.email);

	inserimento_utenti(&tmp);
	p->id.testa = tmp;

	while((curr!=NULL) && (curr->id.email, precedente->id.email)>0) {
	precedente = curr;
	curr = curr->next;
	}
	if(curr == *head)
		*head = p;
	else
		precedente->next = p;
	p->next = curr;
}

void scrivi_su_file(struct nodo_id *head) {
	struct nodo_id *p = NULL;
	FILE *fp;
	p = head;

	fp = fopen("utenti.txt","w");
	if(fp == NULL) {
	printf("ERRORE!!\n");
	return;
	}
	while(p!=NULL) {
	fprintf(fp,"%s %s %s %s\n", p->id.testa->reg.nome, p->id.testa->reg.cognome, p->id.testa->reg.password, p->id.email);
	p = p->next;
	}
	fclose(fp);
}


void inserimento_testa(struct nodo_t **head, int GG, int MM, int AA, float inizio_turno, float fine_turno, int prenotazioni, int max) {
	struct nodo_t *p;
	p = (struct nodo_t *)malloc(sizeof(struct nodo_t));
	p->turn.GG = GG ;
	p->turn.MM = MM;
	p->turn.AA = AA;
	p->turn.inizio_turno = inizio_turno;
	p->turn.fine_turno = fine_turno;
	p->turn.max = max;
	p->turn.prenotazioni = prenotazioni;
	p->next = *head;
	*head = p;
}

void importa_turni(struct nodo_t **head) {
	int GG, MM, AA, max, prenotazioni;
	float inizio_turno, fine_turno;
	FILE *f;

	f = fopen("turni.txt","r");
	if(f == NULL) {
	printf("Errore!!\n");
	return;
	}
	while(fscanf(f,"%d/%d/%d %f %f %d %d", &GG, &MM, &AA, &inizio_turno, &fine_turno, &prenotazioni, &max)!=EOF) {
	inserimento_testa(head, GG, MM, AA, inizio_turno, fine_turno, prenotazioni, max);
	}
	fclose(f);
}

void visualizza_turni(struct nodo_t *head) {
	struct nodo_t *p;
	p = head;

	if(p == NULL) {
	printf("ERRORE!! La lista è vuota\n");
	return;
	}

	while(p!=NULL) {
	printf("%d/%d/%d %.2f %.2f %d %d\n", p->turn.GG, p->turn.MM, p->turn.AA, p->turn.inizio_turno, p->turn.fine_turno, p->turn.prenotazioni, p->turn.max);
	p = p->next;
	}
}

void inserimento_turno(struct nodo_t **head) {
	int GG, MM, AA, prenotazioni, max;
	float inizio_turno, fine_turno;

	printf("Inserisci la data (GG/MM/AA) del turno da inserire\n");
        scanf("%d/%d/%d", &GG, &MM, &AA);
        printf("Inserisci l'orario di inzio del turno\n");
        scanf("%f", &inizio_turno);
        printf("Inserisci l'orario di fine del turno\n");
        scanf("%f", &fine_turno);
        printf("Inserisci il numero di persone che hanno effettuato la prenotazione\n");  //Inserire 0 perchè inizialmente non è stata fatta nessuna prenotazione per il suddetto turno!!
        scanf("%d", &prenotazioni);
        printf("Inserisci il numero massimo di persone che possono prendere parte al turno\n");
        scanf("%d", &max);
	inserimento_testa(head, GG, MM, AA, inizio_turno, fine_turno, prenotazioni, max);
}

void scrivi_turni_file(struct nodo_t *head) {
	FILE *f;
	struct nodo_t *p;
	p = head;

	f = fopen("turni.txt","w");
	if(f == NULL) {
	printf("ERRORE!!!\n");
	return;
	}

	while(p!=NULL) {
	fprintf(f,"%d/%d/%d %.2f %.2f %d %d\n", p->turn.GG, p->turn.MM, p->turn.AA, p->turn.inizio_turno, p->turn.fine_turno, p->turn.prenotazioni, p->turn.max);
	p = p->next;
	}
	fclose(f);
}

void modifica_turni(struct nodo_t *head) {
	struct nodo_t *p;
	p = head;
	int GG, MM, AA, scelta_modifica;
	char ch;

	while((ch = getchar()) != '\n' && ch != EOF);

	printf("Per modificare il turno, inserire la data del turno prestabilito\n");
	scanf("%d/%d/%d", &GG, &MM, &AA);

	while(p!=NULL && GG != p->turn.GG && MM != p->turn.MM && AA != p->turn.AA) {
		p = p->next;
	}

	if(p == NULL) {
	printf("La data inserita non è presente\n");
	} else {
	printf("La data inserita è presente\n");
	printf("Cosa vuoi modificare?\n");
	printf("[1] Modifica la data del turno\n");
	printf("[2] Modifica l'orario di inzio e fine del turno\n");
	printf("[3] Modifica sia la data sia l'orario del turno\n");
	printf("[4] Modifica numero massimo di persone in un turno\n");
	printf("Inserisci la scelta\n");
	scanf("%d", &scelta_modifica);
	while(scelta_modifica<1 || scelta_modifica>4) {
	printf("Errore!! Non è possibile modificare nulla\n");
	printf("Inserisci nuova scelta\n");
	scanf("%d", &scelta_modifica);
	}
		switch(scelta_modifica) {
			case 1:
				system("clear");
				printf("Inserisci nuova data del turno\n");
				scanf("%d/%d/%d", &p->turn.GG, &p->turn.MM, &p->turn.AA);
				visualizza_turni(head);
				scrivi_turni_file(head);
				break;
			case 2:
				system("clear");
				printf("Inserisci il nuovo orario di inzio del turno\n");
				scanf("%f", &p->turn.inizio_turno);
				printf("Inserisci il nuovo orario della fine del turno\n");
				scanf("%f", &p->turn.fine_turno);
				visualizza_turni(head);
                                scrivi_turni_file(head);
				break;
			case 3:
				system("clear");
                                printf("Inserisci nuova data del turno\n");
                                scanf("%d/%d/%d", &p->turn.GG, &p->turn.MM, &p->turn.AA);
                                printf("Inserisci il nuovo orario di inzio del turno\n");
                                scanf("%f", &p->turn.inizio_turno);
                                printf("Inserisci il nuovo orario della fine del turno\n");
                                scanf("%f", &p->turn.fine_turno);
                                visualizza_turni(head);
                                scrivi_turni_file(head);
				break;
			case 4:
				system("clear");
				printf("Inserisci nuovo numero massimo di persone in un turno\n");
				scanf("%d", &p->turn.max);
                                visualizza_turni(head);
                                scrivi_turni_file(head);
				break;
		 }
	}
}

void cancella_turno(struct nodo_t **head) {
	struct nodo_t *p;
	struct nodo_t *curr = *head, *precedente = *head;
	int GG, MM, AA;
	char ch;

	while((ch = getchar()) != '\n' && ch != EOF);

	printf("Inserisci la data del turno da eliminare\n");
	scanf("%d/%d/%d", &GG, &MM, &AA);

	while(curr!= NULL && GG != curr->turn.GG && MM != curr->turn.MM && AA != curr->turn.AA) {
	precedente = curr;
	curr = curr->next;
	}
	if(curr == NULL)
	return;
	if(curr == *head)
		*head = curr->next;
	else
		precedente->next = curr->next;
	free(curr);
}

void visualizza_turni_disponibili(struct nodo_t *head) {
	struct nodo_t *p;
	p = head;

	if(p == NULL) {
	printf("Errore!! La lista è vuota\n");
	return;
	}

	while(p!=NULL) {
	if(p->turn.prenotazioni < p->turn.max) {
	printf("%d/%d/%d %f %f %d %d\n", p->turn.GG, p->turn.MM, p->turn.AA, p->turn.inizio_turno, p->turn.fine_turno, p->turn.prenotazioni, p->turn.max);
	}
	p = p->next;
	}
}

void inserimento_in_turno(struct nodo_t *head) {
	struct nodo_t *p;
	p = head;
	int GG, MM, AA, max = 5;

	printf("Inserisci la data del turno in cui vuoi effettuare la prenotazione\n");
	scanf("%d/%d/%d", &GG, &MM, &AA);

	while(p!=NULL) {
		if(GG == p->turn.GG && MM == p->turn.MM && AA == p->turn.AA) {
			if(p->turn.prenotazioni < max) {
			p->turn.prenotazioni += 1;
			printf("Prenotazione effettuata con successo!!\n");
			} else {
				printf("Non ce n'è posto!!\n");
			}
		}
	p = p->next;
	}
}

void rimozione_da_turno(struct nodo_t *head) {
	struct nodo_t *p;
	p = head;
	int GG, MM, AA;

	if(p == NULL) {
	printf("Errore!!\n");
	return;
	}

	printf("Inserisci la data del turno da cui rimuovere la prenotazione\n");
	scanf("%d/%d/%d", &GG, &MM, &AA);

	while(p!=NULL) {
		if(GG == p->turn.GG && MM == p->turn.MM && AA == p->turn.AA) {
                        if(p->turn.prenotazioni != 0) {
                        p->turn.prenotazioni -= 1;
                        printf("Rimozione effettuata con successo!!\n");
                        } else {
                                printf("Non è possibile effettuare la rimozione perchè il turno non presenta nessuna prenotazione\n");
                        }
                }
        p = p->next;
        }
}
