BEGIN {
	lastcommand="none"
}

{
	lastcommand=$8
}

END {
	print lastcommand	
}
