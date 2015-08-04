#!perl 

while(<>)
{
	chomp;
	if(!/\.csv$/)
	{
		next;
	}
	my $bak=$_.".bak";
	my $name=$_;
	system "mv $name $bak";
	system "iconv -f cp936 -t UTF-8 $bak > $name";
}
