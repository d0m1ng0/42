# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    robust_calc.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/04 13:17:30 by dverdini          #+#    #+#              #
#    Updated: 2026/04/04 13:18:17 by dverdini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Andiamo a chiudere il Module 00: Growing Code con l'ultimo grande pilastro: l'Ex03.
In questo esercizio, di solito, il Subject sposta l'asticella sulla Robustezza e sulla Documentazione. In ambito Quant, questo è il momento in cui passi dal "fare esperimenti" al "mettere in produzione".

1. Cosa chiede il Subject dell'Ex03? (L'Analisi)
Il Subject tipicamente ti sfida a gestire l'errore umano o i dati corrotti. Ti chiede di:

Gestire le Eccezioni (try/except): Non permettere mai che il programma crashi (Traceback). Deve morire "con dignità" o gestire l'errore.

Documentazione Professionale: Ogni funzione deve avere una Docstring (solitamente formato Google o NumPy) che descriva parametri, ritorni ed eccezioni sollevate.

Argomenti da Linea di Comando: Usare sys.argv per rendere lo script uno strumento da terminale.

2. La Logica: Come arrivare alla soluzione
Immagina di essere un Hybrid Quant che scrive un parser per caricare i prezzi di chiusura. Se il file è vuoto o contiene una lettera invece di un numero, il tuo sistema non deve esplodere.

Il try-except-else-finally: È la cintura di sicurezza.

La Docstring: È il contratto tra te e chi userà il tuo codice (o tra te e il tuo "io futuro" tra 6 mesi).

Il Naming degli Errori: Non usare un except generico (mai fare except Exception:), ma cattura solo quello che ti aspetti (es. ValueError, ZeroDivisionError).

3. Costruiamo l'Esercizio (Passo dopo Passo)
Crea la cartella ex03 e il file robust_calc.py.

Step 1: Importazione e Documentazione di Modulo
Python
# robust_calc.py
"""
Modulo per il calcolo robusto di indicatori finanziari.
Parte del percorso 42-agentic-cursus.
"""
import sys
Step 2: La Funzione "Blindata"
Python
def calculate_growth_rate(initial_price: float, final_price: float) -> float:
    """
    Calcola il tasso di crescita tra due prezzi.

    Args:
        initial_price (float): Il prezzo all'inizio del periodo.
        final_price (float): Il prezzo alla fine del periodo.

    Returns:
        float: Il tasso di crescita percentuale.

    Raises:
        ZeroDivisionError: Se il prezzo iniziale è zero.
        ValueError: Se i prezzi forniti sono negativi.
    """
    if initial_price < 0 or final_price < 0:
        raise ValueError("I prezzi non possono essere negativi.")
    
    # Questo solleverà automaticamente ZeroDivisionError se initial_price == 0
    return ((final_price - initial_price) / initial_price) * 100
Step 3: Gestione dell'Input e del Flusso
Python
def main() -> None:
    """Punto di ingresso che gestisce gli argomenti da terminale."""
    if len(sys.argv) != 3:
        print("Uso: python3 robust_calc.py <prezzo_iniziale> <prezzo_finale>")
        sys.exit(1)

    try:
        start: float = float(sys.argv[1])
        end: float = float(sys.argv[2])
        
        growth: float = calculate_growth_rate(start, end)
        print(f"Crescita: {growth:.2f}%")

    except ValueError as e:
        print(f"Errore di valore: {e}")
    except ZeroDivisionError:
        print("Errore: Impossibile calcolare la crescita da un prezzo iniziale di zero.")
    except Exception as e:
        print(f"Errore imprevisto: {e}")
4. Perché questo è il livello "Elite"?
Controllo dei Flussi: Hai usato sys.argv per rendere lo script utile (strumento da riga di comando).

Docstring Impeccabile: Se lanci help(calculate_growth_rate) in una console Python, vedrai una documentazione bellissima. Questo è quello che fa un Senior.

Sicurezza dei Dati: Hai previsto che l'utente possa inserire stringhe o numeri assurdi e hai protetto il calcolo.

Validazione Finale del Module 00
Prima di pushare tutto sul tuo GitHub professionale:

mypy --strict robust_calc.py

flake8 robust_calc.py

Test Manuale:

python3 robust_calc.py 100 150 -> Deve dare 50.00%

python3 robust_calc.py 0 150 -> Deve dare l'errore sullo zero.

python3 robust_calc.py abc 150 -> Deve dare errore di valore.

CI SIAMO! Con questo esercizio, il Module 00: Growing Code è completato. Hai dimostrato di saper scrivere codice pulito, tipizzato, documentato e robusto.

Passiamo al Module 01: Cosmic Data? Lì inizieremo a usare Pydantic e a validare flussi di dati reali. VAI?
