## 回顾：软件工程

### 软件工程定义

- IEEE: 软件工程是
  1. 将系统化的、规范的、可度量的方法应用于软件的开发、运行和维护，即将工程化方法应用于软件；
  2. 在（1）中所述方法的研究。
- 软件工程知识体系
  - 以高质量为目标，研究软件生产的过程模型、方法与工具

## Analysis and Design

- Analysis
  - emphasizes an investigation of the problem and requirements, rather than a solution. For example, if a new online trading system is desired, how will it be used? What are its functions?
  - do the **right thing**
- Design
  - emphasizes a conceptual solution (in software and hardware) that fulfills the requirements, rather than its implementation. For example, a description of a database schema and software objects.
  - do the **thing right**

## Object-oriented Analysis and Design 

- Object-oriented analysis

  emphasis on finding and describing the objects—or concepts —in the problem domain. For example, in the case of the flight information system, some of the concepts include Plane, Flight, and Pilot.

- Object-oriented design

  Emphasis on defining software objects and how they collaborate to fulfill the requirements. For example, a Plane software object may have a tailNumber attribute and a getFlightHistory method.

## Unified Modeling Language 

- The UML is standard diagramming language to visualize the results of analysis and design.

- Notation (the UML) is a simple, relatively trivial thing.

- Much more important: Skill in designing with objects.

- Learning UML notation does not help

- The UML is not

  - a process or methodology
  - object-oriented analysis and design
  - guidelines for design

- Three Ways to Apply UML

  - UML as sketch—Informal and incomplete diagrams (often hand sketched on whiteboards) created to explore difficult parts of the problemor solutionspace, exploitingthe power of visual languages.

  - UML as blueprint
    - Relatively detailed design diagrams used either for
      - reverse engineering to visualize and better understanding existing code in UML diagrams,
      - code generation (forward engineering).

  - If reverse engineering, a UML tool reads the source or binaries and generates (typically) UML package, class, and sequence diagrams. help the reader understand the big picture elements, structure, and collaborations.
  - Before programming, some detailed diagrams can provide guidance for code generation (e.g. Java), either manually or automatically with a tool.

- Class-related terms consistent with the UML and the UP,

  - Conceptual class—real-world concept or thing. A conceptual or essential perspective. The UP Domain Model contains conceptual classes.
  - Software class—a class representing a specification or implementation perspective of a software component, regardless of the process or method.
  - Implementation class—a class implemented in a specific OO language such as Java

## Unified Process

- The  Unified  Process  (UP)  represents  a  mainstream approach for software development across the spectrum of project scales.
- The  process  is scalable:  you  need  not use  the  entire framework of the process for every project, only those that are effective.
- The  process  is effective:  it  has  been  successfully employed on a large population of projects. 
- Improves productivity through use of practical methods that you’ve probably used already (but didn’t know it).
- Iterative and incremental approach allows start of work with incomplete, imperfect knowledge

## *Unified Process **Workflows***

- Workflows define a set of activities that are performed
- Workflows  cut  across  the  phases,  but  with  different levels of emphasis in each phase
- The core workflows
  - Business Modeling
  - Requirements analysis
  - Design
  - Implementation
  - Test and Integration

## *Use Case Driven*

- Use case

  - A prose representation of a sequence of actions
  - Actions are performed by one or more actors (human or non-human) and the system itself

  - These actions lead to valuable results for one or more of the actors—helping the actors to achieve their goals

- Use cases are expressed from the perspective of the users, in natural language, and should be understandable by all stakeholders

- ***Use-case-driven* means the development team employs the use cases from requirements gathering through code and test**

## *Architecture Centric*

- Software architecture captures decisions about:
  - The overall structure of the software system
  - The structural elements of the system and their interfaces
  - The collaborations among  these  structural elements  and their expected behavior
- Architecture-centric:  software  architecture  provides  the central point around which all other development evolves 
  - Provides a ‘big picture’ of the system
  - Provides  an  organizational  framework  for  development, evolving the system by attending to modifiability qualities of the system
  - Facilitates reuse

## *Iterative and Evolutionary*

- An iterative and evolutionary approach allows start of development with incomplete, imperfect knowledge
- Iterative and evolutionary the following advantages:
  - Logical progress toward a robust architecture（逐步趋向稳定）
  - Effective management of changing requirements（有效管理需求变化）
  - Continuous integration（持续集成）
  - Early understanding of the system (‘Hello world!’ effect)（尽早接触整个系统）
  - Ongoing risk assessment（在线风险评估）



## The Agile Manifesto

Individuals and interactions over processes and tools

Working software over comprehensive documentation

Customer collaboration over contract negotiation

Responding to change over following a plan



## Agile Methods and Attitudes

The Agile Principles

1. Our highest priority is to satisfy the customer through early and continuous delivery of valuable software.

2. Welcome changing requirements, even late in development.

3. Deliver working software frequently.

4. Business people and developers must work together daily throughout the project.

5. Build projects around motivated individuals.

6. Face-to-face conversation.

7. Working software is the primary measure of progress.

8. Agile processes promote sustainable development.

9. The  sponsors,  developers,  and  users  should  be  able  to  maintain  a  constant  pace indefinitely.

10. Continuous attention to technical excellence and good design enhances agility.

11. Simplicity-the art of maximizing the amount of work not doneis essential.

12. The best architectures, requirements, and designs emerge from self-organizing teams.

13. At regular intervals, the team reflects on how to become more effective, then tunes and adjusts its behavior accordingly.

## Agile Modeling

- **Adopting an agile method does not mean avoiding any modeling**
- **The  purpose  of  modeling  and  models  is  primarily  to  support understanding and communication, not documentation.**
- **Don't model or apply the UML to all or most of the software design.**
- Use the simplest tool possible.
- Don't model alone, model in pairs (or triads) at the whiteboard.
- Create models in parallel.
- Use "good enough" simple notation while sketching with a pen on whiteboards.
- **Know  that  all models  will  be inaccurate,  and  the final  code or design different sometimes dramatically different than the model.**
- Developers  themselves  should  do  the  OO  design  modeling,  for themselves.

## Artifacts, Workers, and Activities 

- An artifact is a piece of information that is used as input to, changed by, or output from a process

- Examples include:

  - Models — use-case, domain, and design
  - Model elements—use case, domain class, design class
  - Diagrams and documents
  - Source code
  - Executable elements

- Some important distinctions:

  Workers participate in the development of the system

  Actors are outside the system and have usage relationships with the system

  Stakeholders encompass both actors and workers, as well as others involved with the project

## *Inception Phase*

- Inception phase: envision the product scope, vision, and business case.
  - Buy and/or build this system?
  - Rough unreliable range of cost ? Is it $10K, ​$100K, millions?
  - Should we proceed or stop?
  - Do the stakeholders have basic agreement on the vision of the  project, and  is  it  worth  investing  in  serious investigation?

- Most requirements analysis during the elaboration phase, in parallel with early production-quality programming and testing

- Inception phase should be relatively short for most projects
  - one or a few weeks long.
  - On many projects, if it is more than a week long, then the point of inception has been missed: It is to decide if the project is worth a serious investigation

## Evolutionary  Requirement 

Requirement are a description of need or desired for a product.

- **Goal** - to **identify** and **document** what is really needed, in a form that clearly communicates to the client and to development team members.
- **Challenge** - to define the requirement unambiguously.

## *Evolutionary  Requirement*

In UP, requirements are categorized according to the FURPS+ model.

- Functional: features, capability, security
- Usability: human factors, help, documentation
- Reliability: frequency of failure, recoverability, predictability
- Performance:  response  times,  throughput,  accuracy, availability, resource usage.
- Supportability: adaptability, maintainability, internationalization, configurability



## *Actors(参与者)*

- Actor: external entity interacts (behavior) with system, such as a person (identified by role), computer system, or organization; for example, a cashier.
- Three kind of Actors
  - Primary actor has user goals fulfilled through using services. (e.g., the cashier). Find user goals to drive the use cases.
  - Supporting actor provides a service (e.g., the automated payment authorization service is an example). Often a computer system, but could be an organization or person. The purpose is to clarify external interfaces and protocols.
  - Offstage actor has an interest in the behavior of the use case, but is not primary or supporting (e.g., a government tax agency).

- 最特殊的参与者
  - 系统时钟 例如：schedule



## Use Case(用例)

- Use case
  - is a collection of related success and failure scenarios that describe an actor using a system to support a goal
  - be text documents, not diagrams
  - Use case modeling is primarily an act of writing text, not drawing diagrams.
  - There is nothing object-oriented about use cases;
  - Use cases are a key requirements input to classic OOA/D.
  - be functional or behavioral requirements that indicate what the system will do. In terms of the FURPS+ requirements types, they **emphasize the "F" **, but can also be used for other types

## Use Case Modeling

- Use case model
  - Be the set of all written use cases; it is a model of the black-box system's functionality and environment.
  - be not the only requirement artifact in the UP. There are also the Supplementary Specification, Glossary, Vision, and Business Rules.
  - may optionally include a UML use case diagram to show the names of use cases and actors, and their relationships. This gives a nice context diagram of a system and its environment.

## Fully Use Case Template

![image-20190703224420405](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190703224420405.png)

## Applying UML: Use Case Diagrams  *

![image-20190703224153948](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190703224153948.png)

![image-20190703224201667](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190703224201667.png)

## *UML活动图基本符号* *

![image-20190703224219695](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190703224219695.png)

## 领域建模Introduction

- A domain model
  - the most important and classic model in OO analysis.
  - be a visual representation of conceptual classes or real situation objects in a domain.
  - Also called conceptual models, domain object models, and analysis object models.
  - "focusing on explaining 'things' and products important to a business domain“, such as POS related things.

- Guideline
  - Avoid a waterfall-mindset big-modeling effort to make a thorough or "correct" domain model
  - it won't ever be either, and such over-modeling efforts lead to analysis paralysis, with little or no return on the investment.

## *Domain Model*

- It provides a conceptualperspective.
  - domain objects or conceptual classes
  - associations between conceptual classes
  - attributes of conceptual classes

- Following elements are not suitable in a domain model
  - Software artifacts, such as a window or a database, unless the domain being modeled is of software concepts, such as a model of graphical user interfaces.
  - Responsibilities or methods

## Domain Model

- A domain model shows real-situation conceptual classes, not software classes
- A domain model does not show software artifacts or classes
- A conceptual class is an idea, thing, or object.
  - Symbol words or images representing a conceptual class.
  - Intension the definition of a conceptual class.
  - Extension the set of examples to which the conceptual class applies

## *Guideline: Create a Domain Model* *

- Bounded by the current iteration requirements under design
  - Find the conceptual classes (see a following guideline).
  - Draw them as classes in a UML class diagram.
  - Add the association ncessary to record relationships for which there is a need to preserve some memory.
  - Add the attributes necessary to fulfill the information requirements

## *Guideline: Find Conceptual Classes*

- Reuse or modifyexisting models.
- Use a category list.
- Identify noun phrases from the case text



## *Guideline: Find Conceptual Classes* *

- Identify noun phrases.
  - Identify the nouns and noun phrases in textual descriptions of a domain, and consider them as candidate conceptual classes or attributes
  - Some of these noun phrases may refer to conceptual classes that are ignored in this iteration (e.g., "Accounting" and "commissions"), and some may be simply attributes of conceptual classes.
  - A weakness of this approach is the imprecision of natural language; different noun phrases may represent the same conceptual class or attribute, among other ambiguities.

## *Guideline: Report Objects Include 'Receipt' in the Model*

- Receipt is a noteworthy term in the POS domain. But perhaps it's only a report of a sale and payment, and duplicate information. Two factors to consider
  - Exclude it: Showing a report of other information in a domain model is not useful since all its information is derived  or duplicated from othersources.
  - Include it: it has a special role in terms of the business rules: It confers the right to the bearer of the receipt to return bought items.

- Since item returns are not being considered in this iteration, Receipt will be excluded.
  - During the iteration that tackles the Handle Returns use case, we would be justified to include it.

## *Guideline: A Common Mistake with Attributes vs. Classes*

If we do not think of some conceptual class X as a number or text in the real world, X is probably a conceptual class, not an attribute.

- In the real world, a store is not considered a number or text, the term suggests a legal entity, an organization, and something that occupies space. Therefore, Store should be a conceptual class.



## *Guideline: When to Model with 'Description' Classes*

A description class contains information that describes something else. For example, a ProductDescription that records the price, picture, and text descriptionof an Item.

- Problems: if implemented in software similar to the domain model, it has duplicate data (space-inefficient, and error-prone). Because the description, price, and itemID are duplicated for every Item instance of the same product
- A particular Item may have a serial number; it represents a physical instance. A ProductDescription wouldn't have a serial number

## Association

- Association

  - a relationship between classes (instances of those classes) that indicates some meaningful and interesting connection.
- Guideline: When to Show an Association?

  - Associations imply knowledge of a relationship that needs to be preserved for some duration.
- Guideline: Avoid Adding Many Associations
  - Many lines on the diagram will obscure it with "visual noise."
- Perspectives: Will the Associations Be Implemented In Software?
  - During domain modeling, an association is not data flows, database foreign key relationships, instance variables, or object connections in software solution.
  - it is meaningful in a purely conceptual perspective in the real domain

- Guideline
  - Name an association based on a ClassName-VerbPhrase- ClassName format where the verb phrase creates a sequence that is readable and meaningful.
  - Association names should start with a capital letter, since an association represents a classifier of links between instances;
  - e.g. Sale Paid-by CashPayment: bad example (doesn't enhance meaning): Sale Uses CashPayment
  - e.g. Player Is-on Square: bad example (doesn't enhance meaning): Player Has Square

- Applying UML: Roles
  - Each end of an association is called a role. Roles may optionally have multiplicity expression, name, navigability.



## *POS Partial Domain Model* *

Check slide picture

![image-20190703224030625](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190703224030625.png)

## Attributes

- An attribute is a logical data value of an object.

- Guideline: When to Show Attributes?
  - Include attributes that the requirements (e.g., use cases) suggest or imply a need to remember information.
  - e.g., a receipt (which reports the information of a sale) in the Process Sale use case normally includes a date and time, the store name and address, and the cashier ID,



## POS SSD: a Process Sale Scenario *

check slide picture

![image-20190703224057810](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190703224057810.png)

## System Sequence Diagram 

- System sequence diagram
  - a picture that shows, for one particular scenario of a use case, the events that external actors generate, their order, and inter-system events.
  - All systems are treated as a black box; the emphasis of the diagram is events that cross the system boundary from actors to systems.
  - During interaction between system and actor, an actor generates system events to a system, usually requesting some system operation to handle the event.
  - UML includes sequence diagrams as a notation that can illustrate actor interactions and the operations initiated by them.

- Guideline: Draw an SSD for a main success scenario of each use case, and frequent or complex alternative scenarios
- SSDs are derivedfrom use cases; they show one scenario

![image-20190703230123571](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190703230123571.png)

## *Sections of a Contract* 

- Operation:Name of operation, and parameters
- Cross References: Use cases this operation can occur within
- Preconditions: Noteworthy assumptions about the state of the system or objects in the Domain Model before execution of the operation.
- Postconditions: The state of objects in the Domain Model after completion of the operation

## *Postconditions* *

- Postconditions
  - describe changes in the state of objectsin the domain model.
  - Domain model state changes include instances created, associationsformed or broken, and attributeschanged.
  - Postconditions are not actions to be performed.

- Postconditions fall into these categories:
  - Instance creation and deletion.
  - Attribute change of value.
  - Associations (UML links) formed and broken.

- Postconditions Related to the Domain Model
  - What instances can be created; What associations can be formed in the Domain Model.

- Motivation:Why Postconditions?
  - Postconditions support fine-grained detail and precision in declaring what the outcome of the operation must be



![image-20190703230756008](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190703230756008.png)



![image-20190704000202220](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190704000202220.png)

![image-20190704000210263](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190704000210263.png)

![image-20190704000219870](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190704000219870.png)

![image-20190704000226221](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190704000226221.png)

![image-20190704000233972](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190704000233972.png)

![ image-20190704000240685](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190704000240685.png)

★★★

![image-20190704000247299](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190704000247299.png)

★★★

![image-20190704000308104](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190704000308104.png)

![image-20190704001813143](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190704001813143.png)

![image-20190704001821428](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190704001821428.png)

![image-20190704001829334](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190704001829334.png)

![image-20190704001833824](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190704001833824.png)

★★★

![image-20190704001839321](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190704001839321.png)

![image-20190704001901981](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190704001901981.png)

![image-20190704001909934](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190704001909934.png)

★★★

![image-20190704001915683](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190704001915683.png)

★★★

![image-20190704001923829](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190704001923829.png)

![image-20190704001945272](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190704001945272.png)

★★★

![image-20190704002011108](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190704002011108.png)

![image-20190704002110033](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190704002110033.png)

![image-20190704003037168](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190704003037168.png)

★★★

![ image-20190704003043422](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190704003043422.png)

★★★

![image-20190704003059941](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190704003059941.png)

![image-20190704003113510](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190704003113510.png)

![image-20190704003123570](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190704003123570.png)

![image-20190704003150156](/Users/mig/Desktop/junior-spring/system-analysis/assets/image-20190704003150156.png)