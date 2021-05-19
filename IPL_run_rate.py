overs_Team_A=float(input("How many overs did the team_A played?\n"))
overs_Team_B=float(input("How many overs did the team_B played?\n"))
if overs_Team_A>20 and overs_Team_B>20:
    print("No. of Overs can not exceeds 20")
elif overs_Team_A<=20 and overs_Team_B<=20:
    run_team_A=int(input("Runs scored by the team_A in played overs"))
    run_team_B=int(input("Runs scored by the team_B in played overs"))
    net_runrate_A=(run_team_A/overs_Team_A)-(run_team_B/overs_Team_B)
    net_runrate_B=(run_team_B/overs_Team_B)-(run_team_A/overs_Team_A)
    print("Team\t\t Net run rate")
    if net_runrate_A>net_runrate_B:
        print("1. Team_A\t", net_runrate_A, "\n2. team_B\t", net_runrate_B)
        print("Team_A topped the ipl match table")
    elif net_runrate_A<net_runrate_B:
        print("1. Team_B\t",net_runrate_B, "\n2. Team_A\t", net_runrate_A)
        print("Team_B topped the ipl match table")
    elif net_runrate_A==net_runrate_B:
        print("1. Team_A\t",net_runrate_A, "\n2. team_B\t", net_runrate_B)
        print("Match is tied")