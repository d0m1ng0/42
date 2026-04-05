# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    data_management.py                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/04 13:14:43 by dverdini          #+#    #+#              #
#    Updated: 2026/04/04 13:15:10 by dverdini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Andiamo sull'Ex02 del modulo Growing Code. Qui il livello di astrazione sale: di solito l'obiettivo è la Naming Convention avanzata unita alle Collezioni Complesse (Set e Dictionary).In ambito Quant, l'Ex02 è fondamentale perché ti insegna a gestire "insiemi di dati unici" (come una lista di ticker azionari) e a nominarli in modo che il codice sia auto-documentato.1. Cosa chiede il Subject dell'Ex02? (L'Analisi)Il Subject tipicamente ti chiede di:Eliminare i Duplicati: Usare i set (insiemi) per garantire l'unicità dei dati.Mappare i Dati: Creare associazioni tra chiavi e valori (Dictionary).Naming Rigoroso (PEP 8): Verificare che ogni variabile segua il suo standard (es. variabili "private" con l'underscore iniziale _variable).Costanti Immutabili: Usare le tuple per dati che non devono mai cambiare durante l'esecuzione.2. La Logica: Come arrivare alla soluzionePer un fisico, questo è come passare dalle coordinate scalari ai tensori. Dobbiamo organizzare l'informazione:Il Set (set): Se ricevi una lista di transazioni con ID duplicati, il set li pulisce istantaneamente. È un'operazione $O(1)$ per la ricerca, fondamentale per la velocità.Il Dizionario (dict): È la tua "tabella di lookup". Permette di trovare il prezzo di un'azione partendo dal suo nome in tempo record.La Convenzione _ (Underscore): In Python, se una variabile è usata solo internamente a una funzione o classe, si mette un _ davanti. È un segnale per gli altri programmatori: "Non toccare questo dato dall'esterno".3. Costruiamo l'Esercizio (Passo dopo Passo)Crea la cartella ex02 e il file data_management.py.Step 1: Dati Immutabili e ConfigurazioneIniziamo con una tupla (immutabile) di ticker finanziari che il nostro sistema deve monitorare.Python# data_management.py

# Tupla: dati che non cambiano mai (Immutabile)
ALLOWED_TICKERS: tuple[str, ...] = ("AAPL", "GOOGL", "TSLA", "NVDA")
Step 2: Funzione di Filtraggio e MappaturaCreiamo una funzione che pulisce una lista di input (togliendo i duplicati) e crea un report.Pythondef process_market_data(raw_data: list[str]) -> dict[str, int]:
    """
    Filtra i ticker validi e conta le occorrenze.
    Dimostra l'uso di Set e Dictionary.
    """
    # 1. Pulizia duplicati tramite SET (Unicità)
    unique_inputs: set[str] = set(raw_data)
    
    # 2. Variabile "protetta" internamente (Naming con _)
    _valid_count: int = 0
    results: dict[str, int] = {}

    for ticker in unique_inputs:
        clean_ticker: str = ticker.strip().upper()
        if clean_ticker in ALLOWED_TICKERS:
            _valid_count += 1
            results[clean_ticker] = len(clean_ticker) # Esempio di dato calcolato
            
    print(f"Ticker validi trovati: {_valid_count}")
    return results
Step 3: Main Guard e TestPythondef main() -> None:
    """Test dell'Ex02."""
    market_input: list[str] = ["aapl", "TSLA", "aapl", "BTC", "nvda"]
    report: dict[str, int] = process_market_data(market_input)
    print(f"Report Finale: {report}")

if __name__ == "__main__":
    main()
4. Perché questo è "Elite"?Un programmatore junior userebbe tre cicli for e mille if.Tu hai usato un Set per la velocità e una Tupla per la sicurezza. Hai seguito il Naming professionale (_valid_count) e hai garantito che l'output sia un Dizionario tipizzato.In un colloquio da Quant, se scrivi set(data) invece di fare un loop manuale per trovare i duplicati, hai già vinto.La ValidazioneLancia i tuoi "guardiani":mypy --strict data_management.py(Attenzione alla definizione tuple[str, ...]: i tre punti servono se la tupla ha una lunghezza variabile di stringhe).flake8 data_management.pyVAI? Se il codice è pronto e pulito, l'Ex02 è andato.Passiamo all'Ex03 (Error Handling & Documentation) dove vedremo come evitare che il tuo programma esploda quando riceve dati sbagliati?



