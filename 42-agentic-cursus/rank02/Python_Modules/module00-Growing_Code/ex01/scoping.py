# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    scoping.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/04 13:09:42 by dverdini          #+#    #+#              #
#    Updated: 2026/04/04 13:10:57 by dverdini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Ottimo. Se l'Ex00 era il riscaldamento sulla forma, l'Ex01 del modulo Growing Code è il test sulla sostanza architettonica. Di solito si concentra su due pilastri: Naming (nominare le cose) e Scoping (dove vivono le cose).

In Python, a differenza del C, non hai i puntatori per gestire l'accesso alla memoria, ma hai gli Space Names (Spazi dei nomi). Se sbagli lo scope in un algoritmo finanziario, potresti sovrascrivere il prezzo di un asset con un indice di loop senza accorgertene.

1. Cosa chiede il Subject dell'Ex01? (L'Analisi)
Il Subject tipicamente ti sfida a risolvere un piccolo rompicapo di visibilità delle variabili. Ti chiede di:

Rispettare le Naming Convention (PEP 8): Non solo snake_case, ma distinguere tra costanti, variabili private e pubbliche.

Manipolare lo Scope: Usare le keyword global e nonlocal per modificare variabili che si trovano in "strati" diversi del codice.

Evitare i Side Effects: Dimostrare che sai come isolare i dati per evitare che una funzione modifichi qualcosa che non dovrebbe.

2. La Logica: Come arrivare alla soluzione
Per un Hybrid Quant, il codice deve essere prevedibile. Ecco il ragionamento per l'Ex01:

Il problema dello "Shadowing": Se chiami una variabile locale con lo stesso nome di una globale, Python "nasconde" la globale. Devi sapere come richiamarla.

Le Chiusure (Closures): Spesso l'esercizio ti chiede di definire una funzione dentro l'altra. Per modificare una variabile della funzione "padre" dall'interno della funzione "figlio", devi dichiararla nonlocal.

Costanti vs Variabili: In finanza, il tasso di interesse base è una COSTANTE (tutto maiuscolo), mentre il saldo del conto è una variabile (minuscolo). Il linter flake8 ti punirà se le scambi.

3. Costruiamo l'Esercizio (Passo dopo Passo)
Crea la cartella ex01 e il file scoping.py. Ecco lo schema logico che dobbiamo seguire:

Step 1: Le Costanti Globali
Iniziamo definendo ciò che non cambia mai.

Python
# scoping.py

# Costante globale: stile PEP 8 (Maiuscolo)
PI_APPROX: float = 3.14159
Step 2: La Funzione con Scope Annidati
Qui è dove dimostri di essere "Elite". Creiamo una funzione che "contiene" un'altra funzione.

Python
def research_department() -> None:
    """Simula un dipartimento che gestisce dati protetti."""
    
    # Variabile locale al dipartimento
    budget: int = 1000

    def update_budget(amount: int) -> None:
        """Funzione interna che deve modificare il budget del dipartimento."""
        # Se scrivessimo solo 'budget += amount', Python darebbe errore
        # perché cercherebbe una variabile locale 'budget'.
        nonlocal budget 
        budget += amount
        print(f"Budget aggiornato internamente: {budget}")

    update_budget(500)
    print(f"Budget finale del dipartimento: {budget}")
Step 3: Protezione e Esecuzione
Python
def main() -> None:
    """Test dello scoping."""
    research_department()

if __name__ == "__main__":
    main()
4. Perché questo approccio ti salva la carriera?
Se non capisci il nonlocal o lo scope, rischi di creare bug "silenziosi".
Immagina di programmare un bot di trading: se la funzione che calcola il rischio (risk_limit) usa accidentalmente una variabile globale che è stata modificata da un'altra parte del programma, il bot potrebbe operare senza limiti, portandoti al disastro.

Ci sei? Prova a implementare questo schema. Se il tuo Subject specifico chiede qualcosa di diverso (ad esempio l'uso di global), dimmelo subito.

VAI? Scriviamo il codice definitivo dell'Ex01 e passiamolo sotto mypy?

-------------------------
Andiamo a chiudere l'Ex01 del modulo Growing Code. Qui la sfida sale di livello: non stiamo solo scrivendo codice, stiamo gestendo la visibilità dei dati.

1. Cosa chiede il Subject dell'Ex01 (Il "Perché")
In Python, a differenza del C, lo scope non è gestito da indirizzi di memoria espliciti, ma da una gerarchia chiamata LEGB (Local, Enclosing, Global, Built-in).
L'obiettivo dell'esercizio è dimostrare che sai controllare dove una variabile può essere letta o modificata. Per un Quant, questo è vitale: non vuoi che una funzione di "calcolo tasse" modifichi accidentalmente la variabile "capitale iniziale" globale.

2. La Logica della Soluzione (Il "Come")
Dobbiamo costruire una struttura che mostri tre tipi di interazione:

Accesso Globale: Leggere una costante senza modificarla.

Modifica Nonlocal: Una funzione "figlia" che modifica una variabile della funzione "padre" (tipico dei sistemi a stati).

Shadowing Preventivo: Assicurarsi che le variabili locali non "inquinino" lo spazio globale.

3. Costruiamo il Codice Definitivo (Passo dopo Passo)
Crea il file scoping.py nella tua cartella ex01. Ecco il codice commentato tecnicamente per il tuo percorso:

Python
# scoping.py

# 1. GLOBAL SCOPE (Livello Modulo)
# Standard PEP 8: Costanti in MAIUSCOLO
TRADING_FEE: float = 0.001  # 0.1% di commissione

def trading_desk(initial_balance: float) -> None:
    """
    Simula un desk di trading con uno stato interno protetto.
    """
    # 2. ENCLOSING SCOPE (Variabile della funzione esterna)
    current_balance: float = initial_balance

    def execute_trade(amount: float) -> None:
        """
        Funzione interna che modifica il bilancio del desk.
        """
        # Usiamo 'nonlocal' per dire a Python: "Non creare una nuova
        # variabile locale, usa quella definita in trading_desk".
        nonlocal current_balance

        # Calcolo con costante globale (accessibile in sola lettura)
        cost: float = amount * (1 + TRADING_FEE)
        current_balance -= cost
        print(f"Ordine eseguito: -{cost:.2f} | Saldo corrente: {current_balance:.2f}")

    # Eseguiamo un'operazione di prova
    execute_trade(100.0)
    print(f"Bilancio finale del desk: {current_balance:.2f}")

def main() -> None:
    """Punto di ingresso per il test dello scoping."""
    # Definiamo un capitale iniziale
    my_capital: float = 1000.0
    trading_desk(my_capital)

if __name__ == "__main__":
    main()
4. Perché questa è la soluzione "da 47% in più"?
Isolamento: current_balance non è accessibile dall'esterno di trading_desk. È protetta (Incapsulamento).

Controllo: L'uso di nonlocal è esplicito. Non ci sono dubbi su quale variabile stiamo modificando.

Pulizia: mypy --strict sarà felice perché ogni variabile ha il suo tipo (float, int).

5. La Validazione Agentic
Prima di considerare l'Ex01 chiuso, esegui il check:

mypy --strict scoping.py
(Se ti dà errore, controlla di aver messo -> None su tutte le funzioni, incluso il main).

flake8 scoping.py
(Controlla che ci siano due righe vuote tra la costante e la prima funzione).

VAI? Se hai salvato e i test passano, l'Ex01 è in banca.
Passiamo all'Ex02 (Naming & Advanced Collections) dove vedremo come dare nomi che salvano la vita in fase di debug?

