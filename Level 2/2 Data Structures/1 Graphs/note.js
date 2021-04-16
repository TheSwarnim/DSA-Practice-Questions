const notesOnQuestions = {
  1: "Gand lag gye isa lagana ma, bellManFord walo na laga di...",

  3: "Pepcoder And Reversing (neecha dekh detail explanation bhi, mene bananya ha yeh 1.5 hr tak gand ghisani padi tab jake bana, par maza aae gya 😎😎",

  5: "Kosaraju Algorithm (Strongly Connected Components) implementation (VVIMP)",

  6: "Mother Vertex implementation(V IMP)",
};

const KosarajuAlgorithm = {
  SSC: "Strongly Connected Components (Another name of this algo",

  1: "Single Node is always a SSC",

  2: "If we can reach from every vertex to every other vertex in a component then it is called SSC",

  3: "All the nodes in a component are always a strongly connected in an undirected graph",

  4: "No of SSC = no. of components {in an undirected graph}",
};

const MotherVertex = "GFG Ka article padh";

const PepcoderAndReversing =
  "So the basic implementation is that \
if we see carefully the answer can be obtained by REVERSING THE ARROW OR (1 + DFS OF NEXT NODE IF WE ASSUME IT TO BE UNDIRECTED GRAPH, what i mean is that hum log 2 map ma graph banaiga ek ma directed items ko rekha ga (as per given in the question) and ek apan yeh assume karka banainga ki wo undirected graph ha, \
\
So hum traverse karna suru karanga from source node (1) aur uska saare undirected graph ki traverse karanga, agar humko directed map ma node milti ha to\
              minReverse = getMinReverseEdges() function \
              aur nahi milta ha to\
              minReverse = 1 + getMinReverseEdges() function \
we also have to handle some conditions such as ";
