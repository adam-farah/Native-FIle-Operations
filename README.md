# Native-FIle-Operations
To create a modification to the default file system capable of performing simple compressions and file conversion

Native File Operations

Adam Farah
Ashton Woollard

Installation Instructions

	1.Place project folder on desktop

	2.Install following modules:

		sudo apt-get install rar
		sudo apt-get install unrar
		sudo apt-get install handbrake-cli
		sudo apt-get install ffmpeg
		sudo apt-get install imagemagick
		sudo apt-get install nautilus-actions
	
	3.Open Nautilus actions
	
	4.Import nautilus profile in nautilus actions
		-profile files can be found in '/project/nautilus profile/'
		
	5. Use either included media files or import your own
	
Command Line Usage

	-Right click file
	
	-Convert file or compress from right click context menu
	
Non Command Line Usage

	-Open project directory in terminal
	-Call tester with correct commands
	
	./tester (orig file type) (new file type) (file name)
	
	eg. './tester png jpg image'
