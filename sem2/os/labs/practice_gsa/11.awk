BEGIN {
	sumpid=0;
	nrlines=0;
}

{
	sumpid += $2
	nrlines += 1
}

END {
	print sumpid/nrlines
}
