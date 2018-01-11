(* ::Package:: *)

BeginPackage[ "OptimizeExpressionToC`"]

OptimizeExpressionToC::usage = "Generates optimized version of expression in C";

Begin[ "Private`"]

OptimizeExpressionToC[expr_] :=
	Module[ {optimizedExpr, mainExpr, n, m, defs, output},
		optimizedExpr = Experimental`OptimizeExpression[expr];
		If[ ToString@optimizedExpr[[1, 0]] == "Block",
		    {n = Length[optimizedExpr[[1, 1]]];
		     mainExpr = optimizedExpr[[1, 2, n + 1]];},
		    {n = 0;
		     mainExpr = Flatten@{optimizedExpr[[1]]};}
		];
		m = Length[mainExpr];
		
		defs  = 
		Table[ "Real " <>
			       ToString@CForm@optimizedExpr[[1, 2, i, 1]]  <>
			       " = " <>
			       ToString@CForm@optimizedExpr[[1, 2, i, 2]] <>
     			       ";\n",
    		       {i, 1, n}];
		
		output = 
		Flatten@
		MapIndexed[ "out("<>StringJoin@Riffle[ToString/@(#2-1),","]<>") = " <> ToString@CForm@#1 <>";\n" &,
		mainExpr, {ArrayDepth[mainExpr]}];
		
		Join[defs,output]
	];

End[]

EndPackage[]



