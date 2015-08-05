#!perl

my $first=1;
if(!open $out_fh, '>>', 'boss.csv'){
	die "Cannot open boss.csv: $!";
}
select $out_fh;

while(<>){
	if($first==1){ $first=0; next; }

	chomp;
	my $cat=1;
	my ($x, $y, $des, $id, $imgNo, $monsterType, $foreTalk, $fTalk, 
		$lTalk, $wTalk, $pre)=split /,/;
	my @foreTalkList=split /;/, $foreTalk;
	my @fTalkList=split /;/, $fTalk;
	my @lTalkList=split /;/, $lTalk;
	my @wTalkList=split /;/, $wTalk;
	my @preList=split /;/, $pre;
	my $lenFore=@foreTalkList,$lenF=@fTalkList, $lenL=@lTalkList; 
	my $lenP=@preList, $lenW=@wTalkList;
	my $NPCId=$id, $next=$id+1;
	$des="bossNPC" if length $des==0;

	$"=",";
	print "$x,$y,$des,$id,$cat,npc,$imgNo,$next,",
		"$lenP,$lenFore,0,0,@foreTalkList,@preList\n";
	$id++, $next++;
	print ",,duel,$id,,fight,,$next,0,0,1,,$monsterType\n";
	$id++, $next++;
	print ",,first,$id,,dialog,,$next,0,$lenF,0,,@fTalkList\n";
	$id++, $next++;
	print ",,is_win,$id,,win,,$next,0,0,2,,$NPCId,",$id+2,"\n";
	$id++, $next++;
	print ",,lose,$id,,dialog,,$next,0,$lenL,0,,@lTalkList\n";
	$id++, $next++;
	print ",,win,$id,,dialog,,$next,0,$lenW,0,,@wTalkList\n";
	$id++, $next++;
	print ",,NPCMv,$id,,move,,-1,0,0,3,,$NPCId,0,0\n";
}
