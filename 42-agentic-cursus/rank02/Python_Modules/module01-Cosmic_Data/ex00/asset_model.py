# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    asset_model.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/04 13:30:09 by dverdini          #+#    #+#              #
#    Updated: 2026/04/05 13:14:37 by dverdini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Andiamo. Entriamo nel Module 01: Cosmic Data.

Se il Module 00 era sulla "forma" (pulizia e stile), il Module 01 è sulla sostanza del dato. In ambito Hybrid Quant, questo è il modulo che ti separa definitivamente dagli amatori. Qui impari che i dati non sono solo "stringhe o numeri", ma sono strutture certificate.

1. Il Salto di Qualità: Dalle Liste a Pydantic
Nel Module 00 usavamo i dizionari: data = {"price": 100.5}.
Il problema? Se qualcuno scrive "100.5" (stringa) invece di 100.5 (float), il tuo algoritmo di trading crasha nel bel mezzo della notte.

Nel Module 01, impariamo a usare Pydantic (v2). È lo standard industriale per la validazione dei dati. Ti permette di definire uno "schema" e Python garantirà che ogni dato che entra nel tuo sistema sia perfetto, convertendolo automaticamente se necessario.

2. Cosa chiede il Subject dell'Ex00 (Module 01)?
Tipicamente, l'Ex00: Data Models ti chiede di:

Definire una Classe di Base: Creare un modello che rappresenti un'entità (es. un'Azione, un Sensore, un Pianeta).

Validazione Automatica: Assicurarsi che i campi abbiano vincoli (es. il prezzo non può essere negativo, il nome non può essere vuoto).

Conversione (Coercion): Dimostrare che se passi "42" a un campo int, Pydantic lo trasforma correttamente.

3. La Logica: Come arrivare alla soluzione
Pensa da Quant Engineer. Hai un flusso di dati che arriva da una API esterna. Non puoi fidarti dell'API. Devi costruire una "dogana" (il Modello).

Il Modello: Eredita da BaseModel.

I Vincoli: Usi Field per impostare limiti (es. gt=0 per "maggiore di zero").

L'Immutabilità: Spesso si imposta frozen=True perché un dato finanziario, una volta validato, non deve essere modificato per errore.

4. Costruiamo l'Ex00 (Passo dopo Passo)
Crea la cartella Rank02/Python_Modules/module01_cosmic_data/ex00 e il file asset_model.py.

Step 1: Installazione (Il tuo ambiente)
Assicurati di avere Pydantic installato nel tuo venv:
pip install pydantic

Step 2: Definizione del Modello "Elite"
Python
from pydantic import BaseModel, Field, ValidationError

class FinancialAsset(BaseModel):
    """
    Modello certificato per un asset finanziario.
    Ogni istanza è garantita dal sistema di validazione.
    """
    ticker: str = Field(..., min_length=1, max_length=5)
    price: float = Field(..., gt=0) # Prezzo deve essere > 0
    volume: int = Field(default=0, ge=0)

    class Config:
        # Impedisce modifiche post-creazione (fondamentale per audit)
        frozen = True
Step 3: La Logica di Test (Il Main)
Python
def main() -> None:
    # Caso 1: Dati corretti (con conversione automatica "150" -> 150.0)
    try:
        apple = FinancialAsset(ticker="AAPL", price="150.5", volume=1000)
        print(f"Asset validato: {apple}")
    except ValidationError as e:
        print(f"Errore inaspettato: {e}")

    # Caso 2: Dati corrotti (Prezzo negativo)
    try:
        bad_asset = FinancialAsset(ticker="TRASH", price=-10.0)
    except ValidationError as e:
        print("\nValidazione fallita correttamente per prezzo negativo:")
        print(e.errors()[0]['msg'])

if __name__ == "__main__":
    main()
Perché questo ti rende un professionista?
Un laureato medio scriverebbe una classe Python standard dove puoi cambiare il prezzo in "ciao" in qualsiasi momento.
Tu hai costruito un sistema a prova di proiettile. Se il prezzo non è un numero positivo, l'oggetto non viene nemmeno creato. Questo è il livello di affidabilità che si richiede a chi gestisce capitali.

Validazione
mypy --strict asset_model.py (Mypy ha un plugin specifico per Pydantic che adorerai).

flake8 asset_model.py.

VAI? Se hai capito come la "dogana" di Pydantic protegge il tuo codice, l'Ex00 è tuo. Passiamo all'Ex01 (Nested Models) dove vedremo come gestire strutture dati complesse (es. un Portafoglio che contiene più Asset)?


