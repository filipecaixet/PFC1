using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using UltraDES;

namespace teste
{
    class Program
    {
        private static void ShowDisablement(DeterministicFiniteAutomaton S, DeterministicFiniteAutomaton G, int limit)
        {
            var statesAndEventsList = S.DisabledEvents(G);
            int i = 0;
            foreach (var pairStateEventList in statesAndEventsList)
            {
                Console.WriteLine("\tState: {0}", pairStateEventList.Key.ToString());

                foreach (var _event in pairStateEventList.Value)
                {
                    Console.WriteLine("\t\tEvent: {0}", _event.ToString());
                }
                Console.Write("\n");

                if (++i >= limit) break;
            }
        }
        static void Main(string[] args)
        {
            State s1 = new State("s1", Marking.Marked);
            State s2 = new State("s2", Marking.Unmarked);
            State s3 = new State("s3", Marking.Unmarked);
            State s4 = new State("s4", Marking.Unmarked);
            
			Event a1 = new Event("a1", Controllability.Controllable);      //liga esteira 1
            Event b1 = new Event("b1", Controllability.Uncontrollable);    //desliga esteira 1
            
			Event a2 = new Event("a2", Controllability.Controllable);      //liga "para frente" esteira 2
            Event b2 = new Event("b2", Controllability.Uncontrollable);    //desliga "para frente" esteira 2  
            
			Event a3 = new Event("a3", Controllability.Controllable);      //liga "para tras" esteira 2 
            Event b3 = new Event("b3", Controllability.Uncontrollable);    //liga "para tras" esteira 2
            
			Event a4 = new Event("a4", Controllability.Controllable);      //liga "para frente" esteira 3
            Event b4 = new Event("b4", Controllability.Uncontrollable);    //desliga "para frente" esteira 3
            
			Event a5 = new Event("a5", Controllability.Controllable);      //liga "para tras" esteira 3
            Event b5 = new Event("b5", Controllability.Uncontrollable);    //desliga "para tras" esteira 3
            
			Event a6 = new Event("a6", Controllability.Controllable);      //liga/mexe motor para derrubar peca
            Event b6 = new Event("b6", Controllability.Uncontrollable);    //peça cai/volta motor para posicao inicial
            
			Event bv = new Event("bv", Controllability.Uncontrollable);    //objeto vermelho detectado
            Event ba = new Event("ba", Controllability.Uncontrollable);    //objeto azul detectado
            
			Event bp = new Event("bp", Controllability.Uncontrollable);    //objeto pequeno detectado
            Event bg = new Event("bg", Controllability.Uncontrollable);    //objeto grande detectado

            //----------------------------
            // Esteiras
            //----------------------------
            var G1 = new DeterministicFiniteAutomaton(new[]
            {
                new Transition(s1, a1, s2),
                new Transition(s2, b1, s1)
            }, s1, "g1");

            var G2 = new DeterministicFiniteAutomaton(new[]
            {  
				new Transition(s1, a2, s2),
                new Transition(s2, b2, s1),
                new Transition(s1, a3, s3),
                new Transition(s3, b3, s1)       
             }, s1, "g2");

            var G3 = new DeterministicFiniteAutomaton(new[]
            {
				new Transition(s1, a4, s2),
                new Transition(s2, b4, s1),
                new Transition(s1, a5, s3),
                new Transition(s3, b5, s1)
             }, s1, "g3");

            //----------------------------
            // Servomotor
            //----------------------------
            var G4 = new DeterministicFiniteAutomaton(new[]
			{
                new Transition(s1, a6, s2),
                new Transition(s2, b6, s1)
            }, s1, "g4");

            //----------------------------
            // Sensores
            //----------------------------
            var sensorCor = new DeterministicFiniteAutomaton(new[]
            {
				new Transition(s1, bv, s1),
                new Transition(s1, ba, s1)
            }, s1, "sc");

            var sensorTamanho = new DeterministicFiniteAutomaton(new[]
            {
				new Transition(s1, bp, s1),
                new Transition(s1, bg, s1)
            }, s1, "st");


            //----------------------------
            // Especificações
            //----------------------------

            //Esteira 2 so liga quando chegar objeto(quando b1 acontece)
            var E1 = new DeterministicFiniteAutomaton(new[]
            {
                new Transition(s1, b1, s2),
                new Transition(s2, a2, s1),
                new Transition(s2, a3, s1)

            }, s1, "e1");
            
			//Esteira 3 so liga quando chegar objeto(quando b2 acontece)
            var E2 = new DeterministicFiniteAutomaton(new[]
            {
				new Transition(s1, b2, s2),
                new Transition(s2, a4, s1),
                new Transition(s2, a5, s1)

            }, s1, "e2");

			//Objeto vermelho grande detectado (já corrigido - necessidade de autos laços dos sensores)
			var E3 = new DeterministicFiniteAutomaton(new[]
			{
				new Transition(s1, bg, s1),
				new Transition(s1, bv, s2),
				new Transition(s2, bv, s2),
                new Transition(s2, bg, s3),
				new Transition(s3, bg, s3),
				new Transition(s3, bv, s3),
				new Transition(s3, a6, s1)

            }, s1, "e3");
            
			//Objeto vermelho pequeno detectado (já corrigido - )
            var E4 = new DeterministicFiniteAutomaton(new[]
			{
				new Transition(s1, bp, s1),
				new Transition(s1, bg, s1),
				new Transition(s1, bv, s2),
				new Transition(s2, bv, s2),
				new Transition(s2, bp, s2),
				new Transition(s2, bg, s2),
				new Transition(s2, a4, s1)
                
			}, s1, "e4");
			//Objeto azul grande detectado (ja foi corrigido)
            var E5 = new DeterministicFiniteAutomaton(new[]
			{
				new Transition(s1, bg, s1),
				new Transition(s1, ba, s2),
				new Transition(s2, ba, s2),
				new Transition(s2, bg, s3),
				new Transition(s3, ba, s3),
                new Transition(s3, bg, s3),
				new Transition(s3, a3, s1)
			}, s1, "e5");

			//Objeto azul pequeno detectado (ja foi corrigido)
            var E6 = new DeterministicFiniteAutomaton(new[]
			{
				new Transition(s1, bp, s1),
				new Transition(s1, ba, s2),
				new Transition(s2, ba, s2),
				new Transition(s2, bp, s3),
				new Transition(s3, ba, s3),
				new Transition(s3, bp, s3),
				new Transition(s3, a5, s1)
			}, s1, "e6");


            //planta global
            var planta = DeterministicFiniteAutomaton.ParallelComposition(G1, G2, G3, G4, sensorCor, sensorTamanho);
            
            //numero de estados e transicoes da planta global
			Console.Write("\n planta num states {0}", planta.Size);
            Console.Write("\n planta num transitions {0}", planta.Transitions.Count());

            //especificacao global
            var spec = DeterministicFiniteAutomaton.ParallelComposition(E1, E2, E3, E4, E5, E6);

            //numero de estados e transicoes das especificacoes global
            Console.Write("\n spec num states {0}", spec.Size);
			Console.Write("\n spec num transitions {0}", spec.Transitions.Count());

            // listas de plantas e especificaçoes
            var plant = new[]{G1, G2, G3, G4, sensorCor, sensorTamanho}.ToList();
			var espec = new[]{ E1, E2, E3, E4, E5, E6 }.ToList();

            foreach (var p in plant)
            {
                p.drawSVGFigure(p.Name, true);
                //spc.showAutomaton();
            }


            foreach (var spc in espec){
				spc.drawSVGFigure(spc.Name, true);
				//spc.showAutomaton();
			}

            
			/*
            var espec = DeterministicFiniteAutomaton.ParallelComposition(E1,E2,E3,E4,E5,E6);
            var K = planta.ParallelCompositionWith(espec);

            Console.WriteLine("\tPlant: {0} states", planta.Size);
            Console.WriteLine("\tSpecification: {0} states", espec.Size);
            Console.WriteLine("\tK: {0} states", K.Size);
           */
            
			//Supervisor monolitico
            var Sup = DeterministicFiniteAutomaton.MonolithicSupervisor(
				plant, // global plant
                espec, // global specification
                true
            );
            Console.WriteLine("\tSupervisor: {0} states", Sup.Size);
			Console.WriteLine("\tTransitions: {0}", Sup.Transitions.Count());
			//Sup.drawSVGFigure("Gs", true);
			//Sup.showAutomaton("sup");

            //Supervisor modular           
            List<DeterministicFiniteAutomaton> plants;
            // computes the local modular supervisors
            var sups = DeterministicFiniteAutomaton.LocalModularSupervisor(
				new[] { G1, G2, G3, G4, sensorCor, sensorTamanho }, // plantas
                new[] { E1, E2, E3, E4, E5,E6 }, // Especificações
                out plants
            ).ToArray();

            //sups[0].drawSVGFigure("Gs", true);

            foreach (var spml in sups)
            {
                //spml.drawSVGFigure(spml.Name, true);
                spml.showAutomaton();
            }

            // print de info dos supervisores modulares
            foreach (var su in sups){
				Console.WriteLine("\tSupervisor_Mod_ {0} : {1} states", su.Size,su.Name);				
			}
            Console.WriteLine("\n num Supervisores_modulares: {0}", sups.Count());

			// this is used to prevent the program from closing immediately
			Console.Read();
        }
    }
}
