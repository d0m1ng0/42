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

