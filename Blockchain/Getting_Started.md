# Getting Started

### What are Ethereum Dapps?
> Dapps are the decentralized applications that runs on a peer-to-peer network unlike traditional web apps that runs on centralized servers. When these dapps are built over ethereum network, these are known as “ethereum dapps”. In decentralized apps, all the users’ data is stored on immutable distributed ledger and every participating nodes have a copy of that ledger. These dapps logic that runs on the blockchain nodes is written in solidity language and traditionally called as “smart contracts”.

### Architecture of our Ethereum Dapp:
![Ethereum_Dapp_Architecture](https://miro.medium.com/max/780/1*JaGJYtKcBKHHIznHGioKJg.png)

- <b>Client’s Browser</b>: It is just like a normal browser of any web application written in html, css and javascript.
- <b>Web3.js</b>: Web3.js is a collection of libraries that enables your browser to interact with blockchain. It enables you to read and write data from smart contracts, transfer ethers between accounts and much more.
- <b>Web3 Provider</b>: Ethereum network contains nodes and all nodes share the same copy of data. Setting a “web3 provider” in web3.js tells our code that which node we are going to read and write data from. We are using Metamask in our implementation that injects its web3 provider in the browser. <b>Metamask</b> is a browser extension for Chrome and Firefox that lets users securely manage their Ethereum accounts and private keys, and use these accounts to interact with websites that are using Web3.js.
- <b>Ethereum Virtual Machine</b>: Every ethereum node in ethereum network runs their own EVM implementation and responsible for running the same instructions of smart contracts over the ethereum network.
- <b>Ganache</b>: It is a software tool which creates a local blockchain on the your system this is the exact simulation of how blockchain actually works. so it is ideal for development sake. https://www.trufflesuite.com/ganache
- <b>Smart Contracts</b>: A smart contract is a computer program or a transaction protocol which is intended to automatically execute, control or document legally relevant events and actions according to the terms of a contract or an agreement. The objectives of smart contracts are the reduction of need in trusted intermediators, arbitrations and enforcement costs, fraud losses, as well as the reduction of malicious and accidental exceptions.
- <b>Solidity</b>: Programming Language in commonly used to write smart contracts. https://docs.soliditylang.org/en/v0.8.7/ 
- <b>Truffle</b>: It makes buidling, testing and deployment of smart contracts easier. https://www.trufflesuite.com/docs/truffle/overview
