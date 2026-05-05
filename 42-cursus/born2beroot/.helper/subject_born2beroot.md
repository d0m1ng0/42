I.  Installazione e Base (Rigidità Assoluta)RequisitoDettaglio ChiaveStato
(✓)AmbienteVirtualBox (o UTM). Snapshot PROIBITI.SODebian (Latest Stable
Raccomandato) o Rocky. GUI PROIBITA (X.org, wayland, ecc.)HostnameIl tuo login
che termina con 42 (es. wil42). Deve essere modificabile al peer
review.PartizionamentoMinimo 2 partizioni crittografate usando LVM (es. /home e
/).AppArmor/SELinuxDeve essere attivo all'avvio (AppArmor per Debian, SELinux
per Rocky).



fondamenta




II.  Sicurezza e Utenti (Politica Ferrea)RequisitoDettaglio ChiaveConfigurazione
NecessariaStato (✓)UtenteUtente con il tuo login + root.  L'utente deve
appartenere ai gruppi user42 e sudo.Creazione utente e assegnazione
gruppi.SSHServizio attivo sulla porta 4242 obbligatoria.  Accesso root PROIBITO
via SSH./etc/ssh/sshd_config (Port 4242, PermitRootLogin no)FirewallUFW (Debian)
o firewalld (Rocky) ATTIVO all'avvio.  Lasciare solo la porta 4242 aperta.Regole
di default deny in entrata; allow per 4242.Politica PasswordScadenza: 30 giorni.
Modifica minima: 2 giorni. Avviso: 7 giorni prima.File /etc/login.defs e
/etc/default/useraddComplessitàMinimo 10 caratteri: Uppercase, Lowercase,
Numero.  Max 3 caratteri identici consecutivi. Non contenere il nome
utente.Moduli PAM (es. pam_cracklib.so o pam_pwquality.so).Vecchia
PasswordAlmeno 7 caratteri diversi dalla precedente (non si applica a
root).Moduli PAM.Cambio PasswordTutte le password (incluso root) devono essere
cambiate dopo aver impostato la politica.Comando passwd.



III. ⚙️ Configurazione Sudo (Archiviazione e Controllo)RequisitoDettaglio
ChiaveConfigurazione NecessariaStato (✓)Tentativi ErroreMassimo 3 tentativi in
caso di password errata.File /etc/sudoersMessaggio ErroreMessaggio
personalizzato in caso di password sudo errata.File /etc/sudoers (Defaults
badpass_message=...)ArchiviazioneOgni azione sudo (input e output) deve essere
archiviata in /var/log/sudo/.File /etc/sudoers (Defaults log_input, Defaults
log_output, Defaults logfile=...)TTYModalità TTY abilitata (necessaria per la
sicurezza).File /etc/sudoers (Defaults requiretty o Defaults
!tty_tickets)Restrizione PATHRestrizione dei percorsi eseguibili per sudo
all'elenco fornito.File /etc/sudoers (Defaults secure_path=...)



IV.  Script monitoring.sh (Bash & Crontab)RequisitoDettaglio ChiaveMetodo
Consigliato (Comandi)Stato (✓)EsecuzioneAll'avvio del server e ogni 10 minuti
via cron.Script in /etc/rc.local (o equivalente) + crontab -e.OutputVisualizzato
su tutti i terminali (wall). Nessun errore visibile.Uso del comando wall.Info
1Architettura e versione del Kernel.uname -a (o uname -r e arch).Info 2N°
processori fisici / N° processori virtuali.lscpu (CPU(s) vs Socket(s))Info 3RAM
disponibile e utilizzo (%).free -m o cat /proc/meminfo.Info 4Storage disponibile
e utilizzo (%).df -h.Info 5Utilizzo corrente CPU (%).mpstat o estrazione da
/proc/stat.Info 6Data e ora dell'ultimo riavvio.who -b o uptime -s.Info 7LVM
attivo (sì/no).lvm pvscan o lvs.Info 8N° connessioni attive (ESTABLISHED).ss -t
state established o netstat.Info 9N° utenti loggati.`whowc -l`.Info 10Indirizzo
IPv4 e MAC.ip a (e/o ifconfig).Info 11N° comandi eseguiti con sudo.Log file
specificato in /var/log/sudo/.




================================================================================
				TUTORIAL
================================================================================
WONDERFUL WORLD OF WIRTUALIZATION

what to learn
- VIRTUALIZATION FUNDAMENTALS -operating system "choose as an operating system
  either the latest stable version of Debian (!!NO!! testing/unstable), or the
  latest stable version of Rocky.  Debian is highly recommended if you are new
  to system administration" . download .iso is a format that recreates the
  content of a  physical dis stable version 13.2.0k source:
  https://www.debian.org/CD/http-ftp/#mirrors -configure VM: user@user~$ lsblk
  "create at least 2 encrypted partitions using LVM" "nee to determine the
  appropriate size for each partition avoiding unnecessary disk usage."

	sda	8gb sda1 487G boot, sda2 1K, sd5 7.5G sd5_crypt 7.5G crypt
	usr--vg-root 2.8G lvm	/ usr--vg-swap_1 976M lvm swap usr--vg00-home
	3.8G lvm	/home sr0 1024M rom
						
	"be asked a few questions about operating system chose... the the
	differences aptitude and apt, what SELinux or AppArmor are"

	"SSH service will be running in mandatory port 4242 in the VM.  not
	possible to connect using SSH as root "the use of ssh by setting up a
	new account."

	"confiure the OS with UFW firewall and leave 4242 open in VM" firewall
	must be active when launch VM	-hostname is the login42. then modify it
	-implement strong password policy expires in 30 days can modify after 2
	days a warning every 7 days before password expiring at least 10
	characters UPPERCASE + LOWERCASE + number) no more than 3 same charaters
	not include the user name FOLLOWING RULE  DO NOT APPLY TO root password
	at least 7 charaters not part of the former password root password
	complies with this policy

	-install configure sudo with strict rules -in additio to root user -> +
	user with login_guest42 be present, and belong to "user42" and "sudo"
	groups -> create new user and assign to group -set up strong
	configuration for sudo grouo . 3 authentication using sudo limited in
	the event incorrect psswd . message displayed if an error occurs using
	sudo (wrong psswd) . actions concerning sudo must be archived (inputs
	and outputs), the log file saved in /var/log/sudo/ . TTY mode enabled
	for secutiry reasons .the paths that can be used by sudo must be
	restricted NOT CLEAR

	- create monitoring.sh script developed in bash -> explain how it works,
	  interupt without modifying it.
	
	BONUS
		
- DEBIAN INSTALLATION
- SYSTEM SECURITY - ssh, ufw firewall, sudo policies
- USER GROUP MANAGEMENT
- LVM Logical volume manager SETUP
- MONITORING SCRIPTS and CRON JOBS
- BONUS SERVICES
- evaluation preparation

