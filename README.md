<b>Example of Pareto Front Calculation Using R-Tree With C++ And Boost</b>

This application demonstrates how to compute the Pareto-Front of a given
data set using a R-Tree.

<a href="https://www.sciencedirect.com/topics/engineering/pareto-front#:~:text=The%20Pareto%20front%20is%20defined,Handbook%20of%20Neural%20Computation%2C%202017">
"The Pareto front is defined as the set of non-dominated solutions, where each objective is considered as equally good"</a>
</br></br>
A pareto-front is typically used in genetic algorithms, in which many objectives are defined, the application of a multi-dimensional tree structure such as the R-Tree is a perfect for this problem.

To Run (within VSCode);

<ul>
<li><b>Ensure project is open within the development container</b></li>
<li><b>Hit F5</b></li>
</ul>

This application was written in C++ using VSCode and includes a devcontainer setup file,
which should create a self-contained environment with all the below requirements installed;

<ul>
<li>CMake</li>
<li>Boost</li>
</ul>

It should be possible to build and run the code with alternative development environments, outside of VSCode.

Host Machine Requirements;

To download VSCode;

https://code.visualstudio.com/download

The VSCode development container plugin is installed;

https://code.visualstudio.com/docs/remote/containers

Docker must also be installed;

https://docs.docker.com/get-docker/

This application, however is configured with linux based containers, and will not work correctly on Windows without modification.
