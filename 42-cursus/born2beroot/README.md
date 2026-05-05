*This project has been created as a part of the 42 curriculum by dverdini*

### Project Description
Born2beroot is a system administration project focused on setting a secur Debian Virtual Machine.i It implements a strict password policy, logical volume management (LVM), and essential services such as SSH and a firewall (UFW).

### OS Choice: Debian vs Rocky Linux
I chose **Debian** over Rocky Linux because of its well known stability and its package manager system apt.
- **Debian (+)**: extremely stable, lightweight, big documentation, the best for server.
- **Debian (-)**: Software packages  in the stable branch can be older compared to other distributions.
- **Rocky (+)**: best for enterprises environments.
- **Rocky (-)**: more complex to configure at the begininning.

### Main Design Choices
**Partitioning**: used LVM to allow dynamic resizing of volumes, ensuring scalability.
**Security Policies**: policy password with "libpam-pwquality" alongside a secure "sudo" configuration that logs all inputs and outputs.
**User Management**: created a dedicated user 'dverdini' belonging to 'sudo' and 'user42' groups, with specific password expiration constraints.
**Services**: setup SSH on port 4242 for remote management, protected by a 'UFW' firewall, and a Lighttpd web server for WordPress (Bonus)

### Comparison
TOOL	|	CHOISE		|ALTERNATIVE	|KEY DIFFERENCE	
OS		Debian		 Rocky Linux	 Debian uses .deb/atp while Rocky .rpm/dnf.
Security 	AppArmor	 SELinux	 Path-based vs Label-based.
Firewall	UFW		 Firewalld	 UFW is a simplified front-end. Firewalld is
						 zone-based and more dynamic.
Hypervisor	VirtualBox	 UTM		 VB is a standard cross-platform hypervisor.
						 UTM is optimized for Apple Silicon hardware.

### Installation and execution
**Installation**: ensure you have Oracle VM VirtualBox installed on your host machine.
- Signature File: the signature.txt file must be present to verify disk integrity.
- Verify integrity: run the following command and compare the output with signature.txt:
shasum born2beroot.vdi
**Execution** : start the VM from the VirtualBox interface.
- Login: use the primary user dverdini (or the root user only if specifically requested during evalutaion).
- SSH access: you can also connect via terminal from host (guest 4242).
	ssh dverdini@localhost -p 4243

### Resources
- Internet. Debian official documentation.
