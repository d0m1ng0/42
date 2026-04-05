# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    hello_garden.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/02 14:17:07 by dverdini          #+#    #+#              #
#    Updated: 2026/04/04 13:07:01 by dverdini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def	format_greeting(name: str = "Tutor") -> str:
	"""
	create an hello formatted for the garden.

	Args:
		name (str): The name of the person to say hello. Defaul: "Tutor".

	Returns:
		str: The message hello complete.
	"""
	# The logic is here
	pass

# manipulation type base: take a string, a list or a dictionary and transform
# them
# standard PEP 8 (Norminette of Python)) snake_case names and spaces correct
#implement type hints: tell explicitly to python and mypy whatdata type I expect

# code must be executable only if launched as script

# PROBLEM: write a function that takes a parameter, clean it from spaces, empty
# case, trturn a string formatted with a specific pattern
#SOLUTION:
# input - str can be dirty ex. " User    "
#-output - clean str and inside a tamplate ex. "Hello User!"
B. Gestire l'Incertezza (Edge Cases)
In C, un puntatore nullo fa crashare tutto. In Python, una stringa vuota "" o composta da soli spazi "   " è l'equivalente del "pericolo".

Logica: Uso il metodo .strip() per togliere gli spazi. Se dopo lo strip la stringa è lunga 0, applico un valore di default (es. "Tutor").

C. Blindare il Tipo
Poiché Python è "dinamico" (puoi cambiare tipo a una variabile a metà strada), il Subject ti impone di usare i Type Hints per simulare la sicurezza del C++.

Logica: Scrivo (name: str) -> str. Questo dice al compilatore (e al recruiter) che sei un programmatore serio che non lascia nulla al caso.

3. La Costruzione del Codice
Ecco come si evolve l'idea in codice, passo dopo passo:

Definisco la funzione con i "binari" (Tipi):
def ft_hello(name: str) -> str:

Pulisco il dato:
clean_name = name.strip()

Controllo di sicurezza:
if not clean_name: clean_name = "Tutor"

Ritorno il risultato:
return f"Hello {clean_name}"

Perché lo facciamo così?
Se scrivi print("Hello " + input), l'AI lo fa meglio di te.
Se scrivi una funzione tipizzata, documentata e con gestione degli errori, stai costruendo un modulo che può finire in un software di gestione rischio di una banca. Lì, se il "nome" di un asset finanziario è vuoto, il sistema deve sapere esattamente cosa fare (default o errore), non crashare.

Ci sei? Se la logica ti è chiara, prova a scrivere la funzione completa sul tuo terminale. Se mypy ti dà un errore, incollamelo: quegli errori sono le "lezioni" più importanti di questo modulo.

VAI? Scriviamo il codice definitivo dell'Ex00?
--------------------------------------------

1. Cosa chiede il Subject (L'Obiettivo)
Il primo esercizio di questa piscina Python (Module 00) ha uno scopo preciso: validare il tuo ambiente e la tua capacità di gestire i tipi.
Non si tratta di risolvere un problema matematico complesso, ma di dimostrare che sai manipolare le stringhe e le collezioni (liste, tuple, dizionari) seguendo le regole ferree del nuovo corso:

Zero errori di stile (PEP 8 via flake8).

Tipizzazione totale (Type Hints verificati da mypy).

Niente librerie esterne (solo Python "puro").

2. La Logica: Come arrivare alla soluzione
Immaginiamo che il Subject ti chieda di creare una funzione che "pulisca" un input e lo inserisca in una struttura dati. Ecco il ragionamento da fare:

Analisi dell'Input: Spesso ti viene data una stringa che potrebbe contenere spazi inutili o essere vuota.

Trasformazione: Devi usare i metodi delle stringhe (come .strip() o .capitalize()).

Struttura Dati: Potrebbe chiederti di inserire questo risultato in una lista o in un dizionario per mostrare che sai come Python gestisce la memoria (molto diversamente dal C).

La "Trappola" del Main: Se scrivi codice fuori dalle funzioni, fallisci. Devi usare il if __name__ == "__main__":.

3. Costruiamo l'esercizio (Passo dopo Passo)
Supponiamo che il compito sia: "Crea una funzione che accetti un nome, lo pulisca, e lo inserisca in un dizionario che rappresenta un 'membro del giardino' con un ID incrementale."

Step 1: Definire la funzione con i "Binari" (Tipi)
Invece di scrivere def f(x):, scriviamo in modo professionale.

Python
def create_garden_member(name: str, member_id: int) -> dict[str, str | int]:
    # name: str -> Mi aspetto una stringa
    # -> dict[...] -> Restituirò un dizionario
Step 2: Pulizia e Logica
Python
    clean_name: str = name.strip().title() # Tolgo spazi e metto la maiuscola
    if not clean_name:
        clean_name = "Anonymous"
    
    # Creazione del dizionario (l'equivalente di una struct in C)
    member_data: dict[str, str | int] = {
        "name": clean_name,
        "id": member_id
    }
    return member_data
Step 3: Il Test Rigoroso (Il Main)
Python
def main() -> None:
    # Testiamo la nostra logica
    user: dict[str, str | int] = create_garden_member("  agentic_student  ", 1)
    print(f"Member Created: {user}")

if __name__ == "__main__":
    main()
4. Perché questa è la soluzione "Elite"?
Affidabilità: Se passi una stringa vuota, il codice non crasha (gestione degli edge cases).

Leggibilità: Un altro programmatore (o un'AI) capisce subito cosa entra e cosa esce grazie ai Type Hints.

Scalabilità: È un modulo pronto per essere importato in un progetto più grande.

Ci sei? Prova a copiare questa logica nel tuo file hello_garden.py.
Una volta fatto, prova a lanciare:
mypy --strict hello_garden.py

Se mypy si arrabbia, è lì che avviene il vero apprendimento. VAI? Dimmi se vuoi
che analizziamo un errore specifico di mypy o se passiamo a integrare questo
codice con il primo vero esercizio del tuo Subject

--------------------------------------------------------

Andiamo a chiudere l'Ex00 con la precisione di un chirurgo.

1. Cosa chiedeva il Subject (Il "Perché")
Il Subject di questo primo esercizio (spesso chiamato starting.py o hello.py nel modulo Growing Code) ti mette davanti a una sfida di migrazione mentale:

In C, per manipolare stringhe e collezioni, devi gestire la memoria manualmente (malloc, free, puntatori).

In Python, le strutture dati sono "oggetti vivi". Il Subject ti chiede di dimostrare che sai muoverti tra Liste (mutabili), Tuple (immutabili), Set (unici) e Dizionari (chiave-valore), rispettando la PEP 8.

2. La Logica della Soluzione (Il "Come")
Per risolverlo, dobbiamo seguire tre passaggi logici:

Isolamento: Non scrivere codice "sciolto". Tutto deve stare dentro funzioni.

Trasformazione: Prendere dei dati grezzi (es. una lista di città o nomi) e modificarli usando i metodi integrati di Python (.append, .update, .replace).

Certificazione: Usare i Type Hints per dire al sistema: "Questo parametro deve essere una lista di stringhe, non altro".

3. Costruiamo il Codice Definitivo (Passo dopo Passo)
Copia questo codice nel tuo file hello_garden.py. Ho inserito dei commenti tecnici che spiegano cosa sta succedendo per ogni riga:

Python
# hello_garden.py

def format_data(raw_name: str) -> str:
    """
    Prende una stringa grezza, toglie gli spazi e la capitalizza.
    In ambito Quant, questa è 'Data Cleaning' di base.
    """
    # .strip() rimuove spazi iniziali/finali
    # .capitalize() mette la prima lettera maiuscola
    clean_name: str = raw_name.strip().capitalize()
    
    # Gestione 'Edge Case': se la stringa è vuota, diamo un default
    if not clean_name:
        return "Unknown Member"
    return clean_name

def main() -> None:
    """
    Punto di ingresso. Qui dimostriamo la padronanza delle Collezioni.
    """
    # 1. LISTA (Ordinata e Mutabile)
    garden_staff: list[str] = ["tutor", "  student  ", "mentor"]
    
    # 2. TRASFORMAZIONE (List Comprehension - Molto Pythonic)
    # Applichiamo la nostra funzione a ogni elemento della lista
    cleaned_staff: list[str] = [format_data(name) for name in garden_staff]
    
    # 3. DIZIONARIO (Associazione Chiave-Valore)
    # Creiamo un record professionale
    garden_info: dict[str, list[str]] = {
        "location": ["42 Paris", "42 Rome"],
        "staff": cleaned_staff
    }

    # Output formattato
    print(f"Garden Info: {garden_info}")

if __name__ == "__main__":
    main()

4. La Prova del Fuoco (I Guardiani)
Adesso, per essere davvero "Elite", non limitarti a lanciare il programma con python3. Devi interrogarlo con gli strumenti di analisi che usano nei grandi fondi d'investimento:

Analisi dei Tipi:
mypy --strict hello_garden.py
Cosa succede: Mypy legge i tuoi -> str e list[str]. Se hai sbagliato a dichiarare un tipo, ti fermerà qui. In un ambiente Quant, questo previene crash da milioni di dollari.

Analisi dello Stile:
flake8 hello_garden.py
Cosa succede: Verifica che tra le funzioni ci siano esattamente due righe vuote, che non ci siano spazi a fine riga e che i nomi siano corretti.

Riepilogo per il tuo Percorso
Abbiamo preso un problema banale (stampare nomi) e lo abbiamo trasformato in un modulo software solido. Abbiamo gestito l'input sporco, abbiamo usato collezioni tipizzate e abbiamo protetto l'esecuzione.

VAI? Se hai salvato il file e i test di mypy/flake8 sono puliti, abbiamo ufficialmente completato l'Ex00.

Vuoi che passiamo all'Ex01 (Naming & Scoping) per vedere come Python gestisce le variabili quando le cose si fanno più complesse?
